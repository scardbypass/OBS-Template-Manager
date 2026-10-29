cmake_minimum_required(VERSION 3.24)
project(obs-template-manager VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(libobs REQUIRED)
find_package(obs-frontend-api REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(obs-template-manager MODULE src/plugin.cpp)
target_link_libraries(obs-template-manager PRIVATE OBS::libobs OBS::obs-frontend-api Qt6::Widgets)
target_compile_definitions(obs-template-manager PRIVATE QT_NO_KEYWORDS)
set_target_properties(obs-template-manager PROPERTIES PREFIX "")
if(WIN32)
  set_target_properties(obs-template-manager PROPERTIES SUFFIX ".dll")
endif()
