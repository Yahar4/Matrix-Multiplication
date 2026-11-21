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

int main(void) {
    Mat a = {.rows = 2, .cols = 2, .data = (float[]){1,2,3,4}};

    mat_print(a);
}
