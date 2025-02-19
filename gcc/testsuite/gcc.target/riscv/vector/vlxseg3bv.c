
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int16x3xm1_t test_vlxseg3bv_int16x3xm1 (const short *address, int16xm1_t index, unsigned int gvl) {
    return vlxseg3bv_int16x3xm1 (address, index, gvl);
}


int16x3xm2_t test_vlxseg3bv_int16x3xm2 (const short *address, int16xm2_t index, unsigned int gvl) {
    return vlxseg3bv_int16x3xm2 (address, index, gvl);
}


int32x3xm1_t test_vlxseg3bv_int32x3xm1 (const int *address, int32xm1_t index, unsigned int gvl) {
    return vlxseg3bv_int32x3xm1 (address, index, gvl);
}


int32x3xm2_t test_vlxseg3bv_int32x3xm2 (const int *address, int32xm2_t index, unsigned int gvl) {
    return vlxseg3bv_int32x3xm2 (address, index, gvl);
}


int64x3xm1_t test_vlxseg3bv_int64x3xm1 (const long *address, int64xm1_t index, unsigned int gvl) {
    return vlxseg3bv_int64x3xm1 (address, index, gvl);
}


int64x3xm2_t test_vlxseg3bv_int64x3xm2 (const long *address, int64xm2_t index, unsigned int gvl) {
    return vlxseg3bv_int64x3xm2 (address, index, gvl);
}


int8x3xm1_t test_vlxseg3bv_int8x3xm1 (const signed char *address, int8xm1_t index, unsigned int gvl) {
    return vlxseg3bv_int8x3xm1 (address, index, gvl);
}


int8x3xm2_t test_vlxseg3bv_int8x3xm2 (const signed char *address, int8xm2_t index, unsigned int gvl) {
    return vlxseg3bv_int8x3xm2 (address, index, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlxseg3b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vlxseg3b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg3b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlxseg3b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg3b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlxseg3b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m1.*vlxseg3b\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m2.*vlxseg3b\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

