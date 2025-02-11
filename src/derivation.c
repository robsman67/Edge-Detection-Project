#include "derivation.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "convolution.h"
#include "image.h"

void gradient_magnitude(float *result, const float *d_x, const float *d_y,
                        int w, int h) {

    float grad; //unsigned value of the grad
    int position = 0;
    for (int i = 0; i < h; i++){ //for the h

        for (int j = 0; j < w; j++){ // for the w
            position = i * w + j; // position of the table
            grad = sqrt(pow((d_x[position]), 2) + pow(d_y[position],2) ); //calcul
            result[position] = fabs(grad); // store the results
        }
    }
}

const float sobel_x[9] = {1, 0, -1, 2, 0, -2, 1, 0, -1};

const float sobel_y[9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};

void derivation_x_direction(float *result, const float *img, int w, int h) {
    convolve(result, img, w, h, sobel_x, 3, 3);
}

void derivation_y_direction(float *result, const float *img, int w, int h) {
    convolve(result, img, w, h, sobel_y, 3, 3);
}
