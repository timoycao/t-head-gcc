
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float32x6xm1_t test_vlxseg6ev_float32x6xm1 (const float *address, int32xm1_t index, unsigned int gvl) {
    return vlxseg6ev_float32x6xm1 (address, index, gvl);
}


float64x6xm1_t test_vlxseg6ev_float64x6xm1 (const double *address, int64xm1_t index, unsigned int gvl) {
    return vlxseg6ev_float64x6xm1 (address, index, gvl);
}


int16x6xm1_t test_vlxseg6ev_int16x6xm1 (const short *address, int16xm1_t index, unsigned int gvl) {
    return vlxseg6ev_int16x6xm1 (address, index, gvl);
}


int32x6xm1_t test_vlxseg6ev_int32x6xm1 (const int *address, int32xm1_t index, unsigned int gvl) {
    return vlxseg6ev_int32x6xm1 (address, index, gvl);
}


int64x6xm1_t test_vlxseg6ev_int64x6xm1 (const long *address, int64xm1_t index, unsigned int gvl) {
    return vlxseg6ev_int64x6xm1 (address, index, gvl);
}


int8x6xm1_t test_vlxseg6ev_int8x6xm1 (const signed char *address, int8xm1_t index, unsigned int gvl) {
    return vlxseg6ev_int8x6xm1 (address, index, gvl);
}


uint16x6xm1_t test_vlxseg6ev_uint16x6xm1 (const unsigned short *address, uint16xm1_t index, unsigned int gvl) {
    return vlxseg6ev_uint16x6xm1 (address, index, gvl);
}


uint32x6xm1_t test_vlxseg6ev_uint32x6xm1 (const unsigned int *address, uint32xm1_t index, unsigned int gvl) {
    return vlxseg6ev_uint32x6xm1 (address, index, gvl);
}


uint64x6xm1_t test_vlxseg6ev_uint64x6xm1 (const unsigned long *address, uint64xm1_t index, unsigned int gvl) {
    return vlxseg6ev_uint64x6xm1 (address, index, gvl);
}


uint8x6xm1_t test_vlxseg6ev_uint8x6xm1 (const unsigned char *address, uint8xm1_t index, unsigned int gvl) {
    return vlxseg6ev_uint8x6xm1 (address, index, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg6e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg6e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlxseg6e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg6e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg6e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m1.*vlxseg6e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlxseg6e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg6e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg6e\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e8,m1.*vlxseg6e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

