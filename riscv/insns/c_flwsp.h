if (xlen == 32) {
  require_either_extension(EXT_ZCF, EXT_ZCMLSD);
  if (p->extension_enabled(EXT_ZCF)) {
    require_fp;
    WRITE_FRD(f32(MMU.load<uint32_t>(RVC_SP + insn.rvc_lwsp_imm())));
  } else { // c.ldsp - Load pair RV32
    require_extension(EXT_ZCMLSD);
    require(insn.rvc_rd() != 0);
    WRITE_RD_PAIR(MMU.load<int64_t>(RVC_SP + insn.rvc_ldsp_imm()));
  }
} else { // c.ldsp
  require_extension(EXT_ZCA);
  require(insn.rvc_rd() != 0);
  WRITE_RD(MMU.load<int64_t>(RVC_SP + insn.rvc_ldsp_imm()));
}
