cmake_minimum_required(VERSION 3.0)
project(SQLIST)

set(SRC_LIST test.cpp SqList.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
