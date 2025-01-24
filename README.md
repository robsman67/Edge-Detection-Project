# Edge Detection Project

This repository contains a C implementation of an edge detection algorithm as part of **Programming 2 - Summer Term 2024** at Saarland University.

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
```bash
make
