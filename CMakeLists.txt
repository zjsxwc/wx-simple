cmake_minimum_required(VERSION 3.14)
project(test)

# 安装依赖 sudo apt-get install build-essential libwxgtk3.0-dev

set(CMAKE_CXX_STANDARD 14)

# 添加 所有 .cpp 源文件名列表 到 变量 SRC_LIST
aux_source_directory(. SRC_LIST)
# 添加 .h 头文件目录
include_directories(.)

# set(wxWidgets_CONFIGURATION mswu)

# 自动导入wxWidget GUI库相关的头文件与源码
find_package(wxWidgets COMPONENTS core base REQUIRED)
# 根据wxWidget文档导入变量 wxWidgets_USE_FILE 下的 .cmake 文件
include(${wxWidgets_USE_FILE})


# 指定要编译生成可执行文件
add_executable(${PROJECT_NAME} ${SRC_LIST})

# 链接动态库
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})


message("SRC_LIST ${SRC_LIST}")
message("wxWidgets_INCLUDE_DIRS ${wxWidgets_INCLUDE_DIRS}")
message("wxWidgets_USE_FILE ${wxWidgets_USE_FILE}")
message("wxWidgets_LIBRARIES ${wxWidgets_LIBRARIES}")
message("wxWidgets_CONFIG_EXECUTABLE ${wxWidgets_CONFIG_EXECUTABLE}")
