#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint32_t rows, cols;
    float *data;
} Mat;

void mat_print(Mat m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf(" %.2f", m.data[i * m.rows + j]);
        }  

        printf("\n");
    }
}


/*
 * 1 2
 * 3 4
 *
 * mult 
 *
 * 4 3 
 * 2 1
 *
 * result 
 *
 * 8 5
 * 20 13
 * */

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

int main(void) {
    Mat a = {.rows = 2, .cols = 2, .data = (float[]){1,2,3,4}};
    Mat b = {.rows = 2, .cols = 2, .data = (float[]){4,3,2,1}};
    Mat c = {.rows = 2, .cols = 2, .data = (float[4]){0}};

    mat_mult(c, a, b);
    mat_print(c);
}
