
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

void test_vsxseg4ev_float16x4xm1 (float16_t *address, int16xm1_t index, float16x4xm1_t a, unsigned int gvl) {
    return vsxseg4ev_float16x4xm1 (address, index, a, gvl);
}


void test_vsxseg4ev_float16x4xm2 (float16_t *address, int16xm2_t index, float16x4xm2_t a, unsigned int gvl) {
    return vsxseg4ev_float16x4xm2 (address, index, a, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vsxseg4e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vsxseg4e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

