cmake_minimum_required(VERSION 3.10)

project(SqList)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(. APP_SRCS) #根目录下的源文件
aux_source_directory(Src LIB_SRCS) #Src目录的源文件

#生成动态库
add_library(common SHARED ${LIB_SRCS})
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/Inc) #链接Inc的头文件

#生成可执行文件
add_executable(main ${APP_SRCS})
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/Inc) 
target_link_libraries(main common) #链接动态库


