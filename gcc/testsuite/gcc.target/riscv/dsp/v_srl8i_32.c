
/* { dg-do assemble } */
/* { dg-skip-if "test P-ext insns" { *-*-* } { "*" } { "-march=rv32*p*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-dsp.h>

uint8x4_t test_v_srl8(uint8x4_t a, const uint32_t b) {
    return __rv__v_srl8 (a, 1);
}

/* { dg-final { scan-assembler "\tsrli8" } }*/

/* { dg-final { cleanup-saved-temps } } */
