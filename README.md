# Edge Detection Project

This repository contains a C implementation of an edge detection algorithm as part of **Programming 2 - Summer Term 2024** at Saarland University.
You can find the subject on the *Project_Description.pdf* file.

## Overview

The project detects edges in grayscale images using the following steps:
1. **Blurring**: Smooth the image using a Gaussian kernel.
2. **Derivative Calculation**: Compute discrete derivatives in x and y directions with Sobel kernels.
3. **Gradient Magnitude**: Calculate the magnitude of the gradient vector for each pixel.
4. **Thresholding**: Binarize the image by applying a threshold to the gradient magnitude.

Input and output images are handled in the Portable Graymap (`.pgm`) format.

---

## Getting Started

### Prerequisites
- **Linux (e.g., WSL, Ubuntu)** or a UNIX-like environment.
- **C Compiler (GCC)** and `make`.
- **Python 3** (for running tests).

### Building
Run the following command to compile the project:
bash :
```make```

The binary edgedetection will be created in the bin/ directory.

## Usage
Run the program with the following syntax:

bash : 
```./bin/edgedetection -T <threshold> <image_file>```

<threshold>: The threshold value for edge detection.
<image_file>: Path to the input image in .pgm format.

## Testing
Run all public tests:

bash : 
```make tests```

## Implementation Details: 
### Algorithm Steps: 

Read Image: Load the input image in .pgm format.

Blur Image: Convolve the image with a Gaussian kernel.

Compute Derivatives: Use Sobel kernels to compute derivatives in x and y directions.

Gradient Magnitude: Combine derivatives to calculate the gradient magnitude.

Thresholding: Apply a threshold to create a binary edge map.

Write Image: Save the output image in .pgm format.

