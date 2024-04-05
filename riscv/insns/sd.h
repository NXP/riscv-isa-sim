if (xlen == 32)
{ // sd - Store pair RV32
    require_extension(EXT_ZILSD);
    require(insn.rs2() % 2 == 0);
} else {
    require(xlen == 64);
}

STORE_D;
