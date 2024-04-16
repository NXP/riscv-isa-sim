if (xlen == 32) {
  require_either_extension(EXT_ZCF, EXT_ZCMLSD);
  if (p->extension_enabled(EXT_ZCF)) {
    require_fp;
    WRITE_RVC_FRS2S(f32(MMU.load<uint32_t>(RVC_RS1S + insn.rvc_lw_imm())));
  } else { // c.ld - Load pair RV32
    require_extension(EXT_ZCMLSD);
    WRITE_RVC_RS2S_PAIR(MMU.load<int64_t>(RVC_RS1S + insn.rvc_ld_imm()));
  }
} else { // c.ld
  require_extension(EXT_ZCA);
  WRITE_RVC_RS2S(MMU.load<int64_t>(RVC_RS1S + insn.rvc_ld_imm()));
}
