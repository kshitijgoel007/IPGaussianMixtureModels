cmake_minimum_required(VERSION 2.8)
project( opencv )
find_package( OpenCV REQUIRED )
set (CMAKE_CXX_STANDARD 11)

add_executable( main src/main.cpp )
add_executable( test_file src/test.cpp)
add_executable(gmm_plot src/gmm_plot)
#add_executable(gmm_eg src/gmm_eg)

target_link_libraries( main ${OpenCV_LIBS} )
target_link_libraries( gmm_plot ${OpenCV_LIBS} )

set(CMAKE_BUILD_TYPE Debug)

