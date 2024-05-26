#include "image.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apply_threshold(float *img, int w, int h, int T) {

    int position;

    for (int i = 0; i < h; i++){ //for the h

        for (int j = 0; j < w; j++){ // for the w
            position = i * w + j; // position of the table
            if(img[position] > T){
                 img[position] = 255.0f;
            }else {
                img[position] = 0.0f;
            }
        }
    }
}

void scale_image(float *result, const float *img, int w, int h) {

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

    if (x < 0) { // out of the img on the left
        x = -x - 1;
    } else if (x >= w) { //out of the right
        x = 2 * w - x - 1;
    }

    if (y < 0) { // out from above
        y = -y - 1;
    } else if (y >= h) { // out from the bottom 
        y = 2 * h - y - 1;
    }

    //if nothing, we juste keep the value of the image
    return img[y * w + x];
}

float *array_init(int size) {
    float *res = calloc(size, sizeof(res[0])); //create a table of size length dynamically
    return res;

    //float *res = NULL;
    //res = array_init(5);
}

void array_destroy(float *m) {

    free(m);

    //array_destroy(m);
}

float *read_image_from_file(const char *filename, int *w, int *h) {
    (void)filename;
    (void)w;
    (void)h;

    FILE *file;
    file = fopen(filename, "r");

    //check if the file is empty
    if(file == NULL){
        fclose(file);
        return NULL;
    }
    char right_type [] = "P2";
    char header [3];
    fscanf(file, "%s \n", header);
    if (strcmp(right_type, header) != 0){
        fclose(file);
        return NULL;
    }

    //store the w and h and check if they are positive
    fscanf(file, "%d %d \n", w, h);

    if (*w < 0 || *h < 0){
        fclose(file);
        return NULL;
    }

    //check if the maximum ‘brightness’ is equal to 255
    int test;
    fscanf(file, "%d \n", &test);
    if(test != 255){
        fclose(file);
        return NULL;
    }

    //create an array
    int size = *w * *h;
    float *img = NULL;
    img = array_init(size);

    int position = 0;
    float value = 0;
    for (int i = 0; i < *h; i++) { //for the h
        for (int j = 0; j < *w; j++) { // for the w
            position = i * *w + j; // position of the table
            fscanf(file, "%f", &value);
            //printf("w = %d with h = %d and value = %f \n", j, i, value);
            //fflush(stdout);
            if(value > 255 || value < 0){
                array_destroy(img);
                return NULL;
            }
            img[position] = value;
        }
    }

    fclose(file);

    return img;
}

void write_image_to_file(const float *img, int w, int h, const char *filename) {

    FILE *file;
    file = fopen(filename, "w");

    //put the header in the file
    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", w, h);
    fprintf(file, "255\n");

    //put each value of the image in the file
    for (int i = 0; i < w * h; i++) {
        //in order to know when to go in the next line
        if (i % w == 0 && i != 0) {
            fprintf(file, "\n");
        }
        fprintf(file, "%d ", (int)img[i]);
    }

    fclose(file);
}
