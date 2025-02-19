
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

void test_vssseg2ev_float16x2xm1 (float16_t *address, long stride, float16x2xm1_t a, unsigned int gvl) {
    return vssseg2ev_float16x2xm1 (address, stride, a, gvl);
}


void test_vssseg2ev_float16x2xm2 (float16_t *address, long stride, float16x2xm2_t a, unsigned int gvl) {
    return vssseg2ev_float16x2xm2 (address, stride, a, gvl);
}


void test_vssseg2ev_float16x2xm4 (float16_t *address, long stride, float16x2xm4_t a, unsigned int gvl) {
    return vssseg2ev_float16x2xm4 (address, stride, a, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vssseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vssseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4.*vssseg2e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

