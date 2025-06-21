#include <npp.h>
#include <cuda_runtime.h>
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load input image
    cv::Mat srcHost = cv::imread("data/Lena.png", cv::IMREAD_COLOR);
    if (srcHost.empty()) {
        std::cerr << "Error: Could not load image!" << std::endl;
        return -1;
    }

    int width = srcHost.cols;
    int height = srcHost.rows;
    int channels = srcHost.channels();

    // Allocate GPU memory
    Npp8u* pSrc, * pDst;
    cudaMalloc(&pSrc, width * height * channels);
    cudaMalloc(&pDst, width * height);  // grayscale: 1 channel

    // Copy image to device
    cudaMemcpy(pSrc, srcHost.data, width * height * channels, cudaMemcpyHostToDevice);

    // Define ROI
    NppiSize oSizeROI = { width, height };

    // Use NPP to convert to grayscale
    nppiRGBToGray_8u_C3C1R(pSrc, width * channels, pDst, width, oSizeROI);

    // Copy result to host
    std::vector<unsigned char> grayData(width * height);
    cudaMemcpy(grayData.data(), pDst, width * height, cudaMemcpyDeviceToHost);

    // Create OpenCV image from raw data
    cv::Mat dstHost(height, width, CV_8UC1, grayData.data());

    // Save output
    cv::imwrite("data/output_grayscale.png", dstHost);

    // Free GPU memory
    cudaFree(pSrc);
    cudaFree(pDst);

    std::cout << "Output saved: output_grayscale.png\n";
    return 0;
}
