if (xlen == 32) {
  require_either_extension(EXT_ZCF, EXT_ZILSD);
  if (p->extension_enabled(EXT_ZCF)) {
    require_fp;
    MMU.store<uint32_t>(RVC_SP + insn.rvc_swsp_imm(), RVC_FRS2.v[0]);
  } else { // c.sdsp - Store pair RV32
    require_extension(EXT_ZCA);
    require(insn.rs2() % 2 == 0);
    MMU.store<uint64_t>(RVC_SP + insn.rvc_sdsp_imm(), RVC_RS2_PAIR);
  }
} else { // c.sdsp
  require_extension(EXT_ZCA);
  MMU.store<uint64_t>(RVC_SP + insn.rvc_sdsp_imm(), RVC_RS2);
}
