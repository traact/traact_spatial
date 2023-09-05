cmake_minimum_required(VERSION 3.16)

set(TARGET_NAME traact_spatial)

project(${TARGET_NAME} VERSION "0.0.0" LANGUAGES CXX)

find_package(traact_base)
list(APPEND CMAKE_MODULE_PATH ${traact_base_INCLUDE_DIR})

include(traact_default_library_setup)

set(SPATIAL_PUBLIC_HEADER  
    src/traact/spatial.h 
    src/traact/spatialBody.h 
    src/traact/spatial_convert.h
    )

set(SPATIAL_SRC 
    src/traact/spatial.cpp 
    src/traact/spatialBody.cpp 
    src/traact/spatial_convert.cpp
    )

add_library(${TARGET_NAME} SHARED ${SPATIAL_SRC})

find_package(traact_core)
find_package(Eigen3)
find_package(Ceres)

target_link_libraries(${TARGET_NAME} traact_core::traact_core Eigen3::Eigen Ceres::ceres)
generate_export_header(${TARGET_NAME} EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/include/traact/traact_spatial_export.h)

target_include_directories(${TARGET_NAME} PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

include(traact_default_library_final)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if (WITH_TESTS)
    add_subdirectory(tests)
endif ()