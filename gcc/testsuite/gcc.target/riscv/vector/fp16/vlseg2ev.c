
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16x2xm1_t test_vlseg2ev_float16x2xm1 (const float16_t *address, unsigned int gvl) {
    return vlseg2ev_float16x2xm1 (address, gvl);
}


float16x2xm2_t test_vlseg2ev_float16x2xm2 (const float16_t *address, unsigned int gvl) {
    return vlseg2ev_float16x2xm2 (address, gvl);
}


float16x2xm4_t test_vlseg2ev_float16x2xm4 (const float16_t *address, unsigned int gvl) {
    return vlseg2ev_float16x2xm4 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vlseg2e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4.*vlseg2e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

