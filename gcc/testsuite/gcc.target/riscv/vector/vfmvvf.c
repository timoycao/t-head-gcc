
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float32xm1_t test_vfmvvf_float32xm1 (float a, unsigned int gvl) {
    return vfmvvf_float32xm1 (a, gvl);
}


float32xm2_t test_vfmvvf_float32xm2 (float a, unsigned int gvl) {
    return vfmvvf_float32xm2 (a, gvl);
}


float32xm4_t test_vfmvvf_float32xm4 (float a, unsigned int gvl) {
    return vfmvvf_float32xm4 (a, gvl);
}


float32xm8_t test_vfmvvf_float32xm8 (float a, unsigned int gvl) {
    return vfmvvf_float32xm8 (a, gvl);
}


float64xm1_t test_vfmvvf_float64xm1 (double a, unsigned int gvl) {
    return vfmvvf_float64xm1 (a, gvl);
}


float64xm2_t test_vfmvvf_float64xm2 (double a, unsigned int gvl) {
    return vfmvvf_float64xm2 (a, gvl);
}


float64xm4_t test_vfmvvf_float64xm4 (double a, unsigned int gvl) {
    return vfmvvf_float64xm4 (a, gvl);
}


float64xm8_t test_vfmvvf_float64xm8 (double a, unsigned int gvl) {
    return vfmvvf_float64xm8 (a, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vfmv\.v\.f" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vfmv\.v\.f" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vfmv\.v\.f" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m8.*vfmv\.v\.f" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vfmv\.v\.f" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vfmv\.v\.f" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vfmv\.v\.f" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m8.*vfmv\.v\.f" } }*/

/* { dg-final { cleanup-saved-temps } } */

