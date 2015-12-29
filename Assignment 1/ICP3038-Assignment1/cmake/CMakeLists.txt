project(ICP3038-Assignment1)

#set (CMAKE_CXX_FLAGS "-std=c++11")

include_directories(../include)

add_executable(assignment1 ../include/Image.h ../src/Image.cpp ../src/test.cpp)
