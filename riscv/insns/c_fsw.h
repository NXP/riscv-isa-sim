if (xlen == 32) {
  require_either_extension(EXT_ZCF, EXT_ZILSD);
  if (p->extension_enabled(EXT_ZCF)) {
    require_fp;
    MMU.store<uint32_t>(RVC_RS1S + insn.rvc_lw_imm(), RVC_FRS2S.v[0]);
  } else {
    require_extension(EXT_ZCA);
    require(insn.rd() % 2 == 0);
    MMU.store<uint64_t>(RVC_RS1S + insn.rvc_ld_imm(), RVC_RS2S_PAIR);
  }
} else { // c.sd
  require_extension(EXT_ZCA);
  MMU.store<uint64_t>(RVC_RS1S + insn.rvc_ld_imm(), RVC_RS2S);
}
