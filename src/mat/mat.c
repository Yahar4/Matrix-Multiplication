#include "mat.h"
#include <stdio.h>

void mat_print(Mat m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf(" %.2f", m.data[i * m.rows + j]);
        }  

        printf("\n");
    }
}

void mat_mult(Mat c, Mat a, Mat b) {
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            uint32_t c_ix = i * c.cols + j;
            c.data[c_ix] = 0.0f;
            for (int k = 0; k < a.cols; k++) {
                c.data[c_ix] += a.data[i * a.cols + k] * b.data[k * b.cols + j];
            }
        } 
    }
}
