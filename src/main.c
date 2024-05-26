#include <stdio.h>
#include <stdlib.h>

#include "argparser.h"
#include "convolution.h"
#include "derivation.h"
#include "gaussian_kernel.h"
#include "image.h"


int main(int const argc, char **const argv) {
    /**
     * Parse arguments. The parsed image file name and threshold are available
     * in the image_file_name and threshold global variables (see argparser.h).
     */
    parse_arguments(argc, argv);

    float *img = NULL;
    int w = 0;
    int h = 0;

    if(read_image_from_file(image_file_name, &w, &h) == NULL){
        printf("can't read the file error");
        fflush(stdout);
        return 1;
    }else{
        img = read_image_from_file(image_file_name, &w, &h);
    }
    int size = w * h;

    /**
     * Read Image from given file.
     *
     * If the input file is broken terminate with return value 1.
     *
     * Hint: The width and height of the image have to be accessible in the
     * scope of this function.
     */

    const char *output_filename = "out_blur.pgm";
    float *result = array_init(size);
    convolve(result, img, w, h, &gaussian_k[0], gaussian_w, gaussian_h);
    write_image_to_file(result, w, h, output_filename);

    read_image_from_file(output_filename, &w, &h);


    /**
     * Blur the image by using convolve with the given Gaussian kernel matrix
     * gaussian_k (defined in gaussian_kernel.h). The width of the matrix is
     * gaussian_w, the height is gaussian_h.
     *
     * Afterwards, write the resulting blurred image to the file out_blur.pgm.
     */

    float *scale_d_x = array_init(size);
    output_filename = "out_d_x.pgm";
    float *d_x = array_init(size);
    derivation_x_direction(d_x, result, w, h);
    scale_image(scale_d_x, d_x, w, h);
    write_image_to_file(scale_d_x, w, h, output_filename);

    output_filename = "out_d_y.pgm";
    float *d_y = array_init(size);
    float *scale_d_y = array_init(size);
    derivation_y_direction(d_y, result, w, h);
    scale_image(scale_d_y, d_y, w, h);
    write_image_to_file(scale_d_y, w, h, output_filename);

    /**
     * Compute the derivation of the blurred image computed above in both x and
     * y direction.
     *
     * Afterwards, rescale both results and write them to the files out_d_x.pgm
     * and out_d_y.pgm respectively.
     */

    output_filename = "out_gm.pgm";
    gradient_magnitude(result, d_x, d_y, w, h);
    scale_image(img, result, w, h);
    write_image_to_file(img, w, h, output_filename);

    /**
     * Compute the gradient magnitude of the blurred image by using the
     * (unscaled!) derivations in x- and y-direction computed earlier.
     *
     * Afterwards, rescale the result and write it to out_gm.pgm.
     */

    output_filename = "out_edges.pgm";
    apply_threshold(result, w, h, threshold);
    write_image_to_file(result, w, h, output_filename);

    /**
     * Apply the threshold to the gradient magnitude.
     * Then write the result to the file out_edges.pgm.
     */

    array_destroy(img);
    array_destroy(result);
    array_destroy(d_x);
    array_destroy(d_y);
    array_destroy(scale_d_x);
    array_destroy(scale_d_y);

    /**
     * Remember to free dynamically allocated memory when it is no longer used!
     */
}

