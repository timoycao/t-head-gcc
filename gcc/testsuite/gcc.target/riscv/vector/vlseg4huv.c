
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint16x4xm1_t test_vlseg4huv_uint16x4xm1 (const unsigned short *address, unsigned int gvl) {
    return vlseg4huv_uint16x4xm1 (address, gvl);
}


uint16x4xm2_t test_vlseg4huv_uint16x4xm2 (const unsigned short *address, unsigned int gvl) {
    return vlseg4huv_uint16x4xm2 (address, gvl);
}


uint32x4xm1_t test_vlseg4huv_uint32x4xm1 (const unsigned int *address, unsigned int gvl) {
    return vlseg4huv_uint32x4xm1 (address, gvl);
}


uint32x4xm2_t test_vlseg4huv_uint32x4xm2 (const unsigned int *address, unsigned int gvl) {
    return vlseg4huv_uint32x4xm2 (address, gvl);
}


uint64x4xm1_t test_vlseg4huv_uint64x4xm1 (const unsigned long *address, unsigned int gvl) {
    return vlseg4huv_uint64x4xm1 (address, gvl);
}


uint64x4xm2_t test_vlseg4huv_uint64x4xm2 (const unsigned long *address, unsigned int gvl) {
    return vlseg4huv_uint64x4xm2 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlseg4hu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vlseg4hu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg4hu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlseg4hu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg4hu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlseg4hu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

