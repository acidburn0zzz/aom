/*
 * Copyright (c) 2020, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */

#ifndef AOM_AV1_COMMON_CNN_TFLITE_H
#define AOM_AV1_COMMON_CNN_TFLITE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "config/aom_config.h"

// Returns true if we can use tflite model for a given qindex.
static INLINE int av1_use_cnn_tflite(int qindex) {
  // TFlite are yet to be ported for other q indices.
  return qindex >= 108 && qindex < 148;
}

// Restores image in 'dgd' with a CNN model using TFlite and stores output in
// 'rst'. Returns true on success.
int av1_restore_cnn_img_tflite(int qindex, const uint8_t *dgd, int width,
                               int height, int dgd_stride, uint8_t *rst,
                               int rst_stride);

// Same as 'av1_restore_cnn_img_tflite' for highbd.
int av1_restore_cnn_img_tflite_highbd(int qindex, const uint16_t *dgd,
                                      int width, int height, int dgd_stride,
                                      uint16_t *rst, int rst_stride,
                                      int bit_depth);

#ifdef __cplusplus
}
#endif

#endif  // AOM_AV1_COMMON_CNN_TFLITE_H