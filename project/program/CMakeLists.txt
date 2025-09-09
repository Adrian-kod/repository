cmake_minimum_required(VERSION 3.10)

project(Program)

set(SOURCE_FILES
        src/main.cpp
)



find_package(Boost 1.60 REQUIRED COMPONENTS date_time)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(Program ${SOURCE_FILES})

target_link_libraries(Program
        PRIVATE
        kolej
        Boost::date_time)

target_include_directories(Program PUBLIC
        ../../include
        ../src/include
        src
)

enable_testing()
