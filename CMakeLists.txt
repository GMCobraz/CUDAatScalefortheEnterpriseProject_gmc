cmake_minimum_required(VERSION 3.10)
project(NPP_Image_Processing LANGUAGES CXX CUDA)

# OpenCV
set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
find_package(OpenCV REQUIRED)

# CUDA Toolkit paths
set(CUDA_ROOT "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.9")
include_directories("${CUDA_ROOT}/include")
link_directories("${CUDA_ROOT}/lib/x64")

# CUDA architecture
set(CMAKE_CUDA_ARCHITECTURES 89)

# Executable
add_executable(npp_image_processing main.cpp)
target_include_directories(npp_image_processing PRIVATE ${OpenCV_INCLUDE_DIRS})

# Link libraries (image processing)
target_link_libraries(npp_image_processing PRIVATE
  ${OpenCV_LIBS}
  nppc nppicc nppidei npps
  cuda cudart
)
