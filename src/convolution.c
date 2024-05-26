#include "convolution.h"

#include <stdlib.h>
#include <stdio.h>

#include "image.h"

void convolve(float *result, const float *img, int w, int h,
              const float *matrix, int w_m, int h_m) {
    int a = w_m /2;
    int b = h_m /2;

    // iterate over each pixel in the image
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            float sum = 0.0f; // result to be store

            // apply the kernel (matrix) for each pixel and store into the results
            for (int i = 0; i < w_m; i++) {
                for (int j = 0; j < h_m; j++) {
                    int img_x = x - a + i; //position from assigment
                    int img_y = y - b + j;
                    float img_value = get_pixel_value(img, w, h, img_x, img_y); // get the correct value
                    float kernel_value = matrix[j * w_m + i]; //corresponding value of the kernel (matrix)
                    sum += img_value * kernel_value;
                }
            }
            result[y * w + x] = sum; // store the result in the right possition
        }
    }
}
