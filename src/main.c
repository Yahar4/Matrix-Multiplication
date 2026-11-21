#include "mat/mat.h"
#include <stdint.h>
#include <stdio.h>

int main(void) {
    Mat a = {.rows = 2, .cols = 2, .data = (float[]){1,2,3,4}};
    Mat b = {.rows = 2, .cols = 2, .data = (float[]){4,3,2,1}};
    Mat c = {.rows = 2, .cols = 2, .data = (float[4]){0}};

    mat_mult(c, a, b);
    mat_print(c);
}
