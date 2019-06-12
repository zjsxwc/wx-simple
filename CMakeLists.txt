cmake_minimum_required(VERSION 3.14)
project(test)

#安装依赖 sudo apt-get install build-essential libwxgtk3.0-dev

set(CMAKE_CXX_STANDARD 14)


aux_source_directory(. SRC_LIST)

#set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)


message(wxWidgets_INCLUDE_DIRS ${wxWidgets_INCLUDE_DIRS})
message(wxWidgets_USE_FILE ${wxWidgets_USE_FILE})
message(wxWidgets_LIBRARIES ${wxWidgets_LIBRARIES})
message(wxWidgets_CONFIG_EXECUTABLE ${wxWidgets_CONFIG_EXECUTABLE})

include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

