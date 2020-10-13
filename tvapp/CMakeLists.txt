cmake_minimum_required(VERSION 3.10)
project(tvapp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "../../installed_libtv/share/cmake/tv/")


find_package(tv REQUIRED)
add_executable(tvapp app.cpp)

target_compile_features(tvapp PUBLIC cxx_range_for)
target_link_libraries(tvapp ${TORCH_LIBRARIES} tv::tv)
set_property(TARGET tvapp PROPERTY CXX_STANDARD 14)
