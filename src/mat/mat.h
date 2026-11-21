#pragma once

#include <stdlib.h>

typedef struct {
    uint32_t rows, cols;
    float *data;
} Mat;

void mat_print(Mat m);
void mat_mult(Mat c, Mat a, Mat b);
