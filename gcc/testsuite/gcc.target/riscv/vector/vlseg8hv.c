
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int16x8xm1_t test_vlseg8hv_int16x8xm1 (const short *address, unsigned int gvl) {
    return vlseg8hv_int16x8xm1 (address, gvl);
}


int32x8xm1_t test_vlseg8hv_int32x8xm1 (const int *address, unsigned int gvl) {
    return vlseg8hv_int32x8xm1 (address, gvl);
}


int64x8xm1_t test_vlseg8hv_int64x8xm1 (const long *address, unsigned int gvl) {
    return vlseg8hv_int64x8xm1 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlseg8h\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg8h\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg8h\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

