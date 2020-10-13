cmake_minimum_required(VERSION 3.1)
project(tv)
set(CMAKE_CXX_STANDARD 14)
set(TV_VERSION 0.7.0)

option(WITH_CUDA "Enable CUDA support" OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CUDA_FLAGS} -O3")

if(WITH_CUDA)
  enable_language(CUDA)
  add_definitions(-D__CUDA_NO_HALF_OPERATORS__)
  add_definitions(-DWITH_CUDA)
  set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} --expt-relaxed-constexpr")
endif()

find_package(Python3 COMPONENTS Development)

find_package(Torch REQUIRED)

file(GLOB HEADERS csrc/*.h)
file(GLOB OPERATOR_SOURCES csrc/cpu/*.h csrc/cpu/*.cpp ${HEADERS} csrc/*.cpp)
if(WITH_CUDA)
  file(GLOB OPERATOR_SOURCES ${OPERATOR_SOURCES} csrc/cuda/*.h csrc/cuda/*.cu)
endif()


add_library(${PROJECT_NAME} SHARED ${OPERATOR_SOURCES} ${IMAGE_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${TORCH_LIBRARIES} Python3::Python)
set_target_properties(${PROJECT_NAME} PROPERTIES EXPORT_NAME tv)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(TV_CMAKECONFIG_INSTALL_DIR "share/cmake/tv" CACHE STRING "install path for tvConfig.cmake")

configure_package_config_file(cmake/tvConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/tvConfig.cmake"
  INSTALL_DESTINATION ${TV_CMAKECONFIG_INSTALL_DIR})

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/tvConfigVersion.cmake
  VERSION ${TV_VERSION}
  COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/tvConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/tvConfigVersion.cmake
  DESTINATION ${TV_CMAKECONFIG_INSTALL_DIR})

install(TARGETS ${PROJECT_NAME}
  EXPORT tvTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

install(EXPORT tvTargets
  NAMESPACE tv::
  DESTINATION ${TV_CMAKECONFIG_INSTALL_DIR})

install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
install(FILES
  csrc/cpu/vision_cpu.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/cpu)
if(WITH_CUDA)
  install(FILES
    csrc/cuda/vision_cuda.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/cuda)
endif()
