
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16xm1_t test_vlsev_mask_float16xm1 (float16xm1_t merge, const float16_t *address, long stride, e16xm1_t mask, unsigned int gvl) {
    return vlsev_mask_float16xm1 (merge, address, stride, mask, gvl);
}


float16xm2_t test_vlsev_mask_float16xm2 (float16xm2_t merge, const float16_t *address, long stride, e16xm2_t mask, unsigned int gvl) {
    return vlsev_mask_float16xm2 (merge, address, stride, mask, gvl);
}


float16xm4_t test_vlsev_mask_float16xm4 (float16xm4_t merge, const float16_t *address, long stride, e16xm4_t mask, unsigned int gvl) {
    return vlsev_mask_float16xm4 (merge, address, stride, mask, gvl);
}


float16xm8_t test_vlsev_mask_float16xm8 (float16xm8_t merge, const float16_t *address, long stride, e16xm8_t mask, unsigned int gvl) {
    return vlsev_mask_float16xm8 (merge, address, stride, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlse\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m2.*vlse\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m4.*vlse\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m8.*vlse\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

