# Image Rotation using NVIDIA NPP with CUDA

## Overview

This project demonstrates the use of NVIDIA Performance Primitives (NPP) library with CUDA to transform rgb to grayscale image. The goal is to utilize GPU acceleration and leveraging the computational power of modern GPUs. The project is a part of the CUDA at Scale for the Enterprise course and serves as a template for understanding how to implement basic image processing operations using CUDA and NPP.

## Code Organization

```bin/```
This folder should hold all binary/executable code that is built automatically or manually. Executable code should have use the .exe extension or programming language-specific extension.

```data/```
This folder should hold all example data in any format. If the original data is rather large or can be brought in via scripts, this can be left blank in the respository, so that it doesn't require major downloads when all that is desired is the code/structure.

```lib/```
Any libraries that are not installed via the Operating System-specific package manager should be placed here, so that it is easier for inclusion/linking.

```src/```
The source code should be placed here in a hierarchical fashion, as appropriate.

```README.md```
This file should hold the description of the project so that anyone cloning or deciding if they want to clone this repository can understand its purpose to help with their decision.

```INSTALL```
This file should hold the human-readable set of instructions for installing the code so that it can be executed. If possible it should be organized around different operating systems, so that it can be done by as many people as possible with different constraints.

```Makefile or CMAkeLists.txt or build.sh```
There should be some rudimentary scripts for building your project's code in an automatic fashion.

```run.sh```
An optional script used to run your executable code, either with or without command-line arguments.

## Key Concepts

Performance Strategies, Image Processing, NPP Library

## Supported OSes

Windows

## Supported CPU Architecture

x86_64

## Dependencies needed to build/run
OpenCV, NPP

## Prerequisites

Download and install the [CUDA Toolkit 12.9](https://developer.nvidia.com/cuda-downloads) for your corresponding platform.
Make sure the dependencies mentioned in [Dependencies]() section above are installed.

## Build and Run

### Windows
```
$ mkdir build && cd build
$ cmake .. -G "Visual Studio 17 2022" -A x64
$ cmake --build . --config Release
```


## Running the Program
After building the project, you can run the program using the following command:

```bash
$ cd build/Release
$ ./npp_image_processing.exe
```
If required, kindly please copy the data folder and opencv_world4110.dll to the same folder where the executable is located

## Output Log
```
Output saved: output_grayscale.png
```