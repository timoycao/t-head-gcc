
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16x8xm1_t test_vlxseg8ev_float16x8xm1 (const float16_t *address, int16xm1_t index, unsigned int gvl) {
    return vlxseg8ev_float16x8xm1 (address, index, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlxseg8e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

