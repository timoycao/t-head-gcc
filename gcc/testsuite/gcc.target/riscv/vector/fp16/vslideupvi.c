
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16xm1_t test_vslideupvi_float16xm1 (float16xm1_t a, const long b, unsigned int gvl) {
    return vslideupvi_float16xm1 ( a, 1, gvl);
}


float16xm2_t test_vslideupvi_float16xm2 (float16xm2_t a, const long b, unsigned int gvl) {
    return vslideupvi_float16xm2 ( a, 1, gvl);
}


float16xm4_t test_vslideupvi_float16xm4 (float16xm4_t a, const long b, unsigned int gvl) {
    return vslideupvi_float16xm4 ( a, 1, gvl);
}


float16xm8_t test_vslideupvi_float16xm8 (float16xm8_t a, const long b, unsigned int gvl) {
    return vslideupvi_float16xm8 ( a, 1, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vslideup\.vi" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vslideup\.vi" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4.*vslideup\.vi" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m8.*vslideup\.vi" } }*/

/* { dg-final { cleanup-saved-temps } } */

