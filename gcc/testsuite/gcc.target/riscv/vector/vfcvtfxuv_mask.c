
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float32xm1_t test_vfcvtfxuv_mask_float32xm1_uint32xm1 (float32xm1_t merge, uint32xm1_t a, e32xm1_t mask, unsigned int gvl) {
    return vfcvtfxuv_mask_float32xm1_uint32xm1 (merge, a, mask, gvl);
}


float32xm2_t test_vfcvtfxuv_mask_float32xm2_uint32xm2 (float32xm2_t merge, uint32xm2_t a, e32xm2_t mask, unsigned int gvl) {
    return vfcvtfxuv_mask_float32xm2_uint32xm2 (merge, a, mask, gvl);
}


float32xm4_t test_vfcvtfxuv_mask_float32xm4_uint32xm4 (float32xm4_t merge, uint32xm4_t a, e32xm4_t mask, unsigned int gvl) {
    return vfcvtfxuv_mask_float32xm4_uint32xm4 (merge, a, mask, gvl);
}


float32xm8_t test_vfcvtfxuv_mask_float32xm8_uint32xm8 (float32xm8_t merge, uint32xm8_t a, e32xm8_t mask, unsigned int gvl) {
    return vfcvtfxuv_mask_float32xm8_uint32xm8 (merge, a, mask, gvl);
}


float64xm1_t test_vfcvtfxuv_mask_float64xm1_uint64xm1 (float64xm1_t merge, uint64xm1_t a, e64xm1_t mask, unsigned int gvl) {
    return vfcvtfxuv_mask_float64xm1_uint64xm1 (merge, a, mask, gvl);
}


float64xm2_t test_vfcvtfxuv_mask_float64xm2_uint64xm2 (float64xm2_t merge, uint64xm2_t a, e64xm2_t mask, unsigned int gvl) {
    return vfcvtfxuv_mask_float64xm2_uint64xm2 (merge, a, mask, gvl);
}


float64xm4_t test_vfcvtfxuv_mask_float64xm4_uint64xm4 (float64xm4_t merge, uint64xm4_t a, e64xm4_t mask, unsigned int gvl) {
    return vfcvtfxuv_mask_float64xm4_uint64xm4 (merge, a, mask, gvl);
}


float64xm8_t test_vfcvtfxuv_mask_float64xm8_uint64xm8 (float64xm8_t merge, uint64xm8_t a, e64xm8_t mask, unsigned int gvl) {
    return vfcvtfxuv_mask_float64xm8_uint64xm8 (merge, a, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vfcvt\.f\.xu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vfcvt\.f\.xu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vfcvt\.f\.xu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m8.*vfcvt\.f\.xu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vfcvt\.f\.xu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vfcvt\.f\.xu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vfcvt\.f\.xu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m8.*vfcvt\.f\.xu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

