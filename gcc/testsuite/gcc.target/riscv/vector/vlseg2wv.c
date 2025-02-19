
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int32x2xm1_t test_vlseg2wv_int32x2xm1 (const int *address, unsigned int gvl) {
    return vlseg2wv_int32x2xm1 (address, gvl);
}


int32x2xm2_t test_vlseg2wv_int32x2xm2 (const int *address, unsigned int gvl) {
    return vlseg2wv_int32x2xm2 (address, gvl);
}


int32x2xm4_t test_vlseg2wv_int32x2xm4 (const int *address, unsigned int gvl) {
    return vlseg2wv_int32x2xm4 (address, gvl);
}


int64x2xm1_t test_vlseg2wv_int64x2xm1 (const long *address, unsigned int gvl) {
    return vlseg2wv_int64x2xm1 (address, gvl);
}


int64x2xm2_t test_vlseg2wv_int64x2xm2 (const long *address, unsigned int gvl) {
    return vlseg2wv_int64x2xm2 (address, gvl);
}


int64x2xm4_t test_vlseg2wv_int64x2xm4 (const long *address, unsigned int gvl) {
    return vlseg2wv_int64x2xm4 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vlseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vlseg2w\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

