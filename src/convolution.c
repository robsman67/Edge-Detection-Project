#include "convolution.h"

#include <stdlib.h>

#include "image.h"

void convolve(float *result, const float *img, int w, int h,
              const float *matrix, int w_m, int h_m) {
    (void)result;
    (void)img;
    (void)w;
    (void)h;
    (void)matrix;
    (void)w_m;
    (void)h_m;

    //int a = w_m /2;
    //int b = h_m /2;

    // iterate over each pixel in the image
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            //float sum = 0.0f;

            // Apply the kernel for each pixel and store into the results
            for (int i = 0; i < w_m; i++) {
                for (int j = 0; j < h_m; j++) {

                }

                }
            }
        }

    // TODO: Implement me!
}
