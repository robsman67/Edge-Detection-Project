#include "image.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apply_threshold(float *img, int w, int h, int T) {
    (void)img;
    (void)w;
    (void)h;
    (void)T;

    int position;

    for (int i = 0; i < h; i++){ //for the h

        for (int j = 0; j < w; j++){ // for the w
            position = i * w + j; // position of the table
            //printf("position = %d", position);
            //printf("image color in this position %f", img[position]);
            if(img[position] > T){
                 img[position] = 255.0f;
            }else {
                img[position] = 0.0f;
            }
        }
    }
}

void scale_image(float *result, const float *img, int w, int h) {
    (void)result;
    (void)img;
    (void)w;
    (void)h;

    int position;
    float min = 255; // in order to compare
    float max = 0;
    float scaled_p;

    //first we must find the min and the max
    for (int i = 0; i < h; i++){ //for the h

        for (int j = 0; j < w; j++){ // for the w
            position = i * w + j; // position of the table
            if (min > img[position]){
                min = img[position];
            }
            if (max < img[position]){
                max = img[position];
            }
        }
    }

    if (max == min){ // because div by 0
        for (int i = 0; i < w; i++){ //for the w
            for (int j = 0; j < h; j++){ // for the h
                position = j * w + i; // position of the table
                result[position] = 0;
            }
        }
    }else {
        for (int i = 0; i < w; i++){ //for the w
            for (int j = 0; j < h; j++){ // for the h
                position = j * w + i; // position of the table
                scaled_p = (img[position] - min) / (max - min) * 255;
                result[position] = scaled_p;
            }
        }
    }
}

float get_pixel_value(const float *img, int w, int h, int x, int y) {
    (void)img;
    (void)w;
    (void)h;
    (void)x;
    (void)y;

    if (x < 0) {
        x = -x - 1;
    } else if (x >= w) {
        x = 2 * w - x - 1;
    }

    if (y < 0) {
        y = -y - 1;
    } else if (y >= h) {
        y = 2 * h - y - 1;
    }

    return img[y * w + x];

    // TODO: Implement me!

    //return 0;
}

float *array_init(int size) {
    (void)size;

    // TODO: Implement me!

    return NULL;
}

void array_destroy(float *m) {
    (void)m;

    // TODO: Implement me!
}

float *read_image_from_file(const char *filename, int *w, int *h) {
    (void)filename;
    (void)w;
    (void)h;

    // TODO: Implement me!

    return NULL;
}

void write_image_to_file(const float *img, int w, int h, const char *filename) {
    (void)img;
    (void)w;
    (void)h;
    (void)filename;

    // TODO: Implement me!
}
