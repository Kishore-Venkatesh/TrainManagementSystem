cmake_minimum_required(VERSION 3.10)

project(TrainManager VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(XML_DIR ${CMAKE_SOURCE_DIR}/data)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(OUTPUT_DIR ${CMAKE_BINARY_DIR})

include_directories(${INC_DIR})

add_executable(TrainManager
            ${SRC_DIR}/main.cpp 
            ${SRC_DIR}/tinyxml2.cpp 
            ${SRC_DIR}/TrainDataParser.cpp 
            ${SRC_DIR}/TrainManagementSystem.cpp 
            )

target_include_directories(TrainManager PRIVATE ${SRC_DIR})

add_custom_command(TARGET TrainManager POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_DIR}/data
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${XML_DIR}
        ${OUTPUT_DIR}/data          
    )
