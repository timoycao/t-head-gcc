
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16x4xm1_t test_vlseg4ev_float16x4xm1 (const float16_t *address, unsigned int gvl) {
    return vlseg4ev_float16x4xm1 (address, gvl);
}


float16x4xm2_t test_vlseg4ev_float16x4xm2 (const float16_t *address, unsigned int gvl) {
    return vlseg4ev_float16x4xm2 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlseg4e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vlseg4e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

