cmake_minimum_required(VERSION 3.26)
project(Humongous_Math_Lib)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp)

add_executable(main src/main.cpp ${SRCS})

target_include_directories(main PUBLIC src/inc/)

find_package(glm CONFIG REQUIRED)
target_link_libraries(main PRIVATE glm::glm)
