cmake_minimum_required(VERSION 2.8)
PROJECT(woot-server)
FIND_PACKAGE(Qt4 REQUIRED)

include_directories ("${PROJECT_SOURCE_DIR}/includes")
SET(CMAKE_CXX_FLAGS "-W -Wall -std=c++0x")

SET(wott_SOURCES src/main.cpp
  src/Boot.cpp
  src/Logger.cpp)
SET(wott_HEADERS includes/Wott.hpp
  includes/Boot.hpp
  includes/Logger.hpp)

QT4_WRAP_CPP(wott_HEADERS_MOC ${wott_HEADERS})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})


SET(QT_USE_QTNETWORK TRUE)

ADD_EXECUTABLE(wott-server ${wott_SOURCES} 
    ${wott_HEADERS_MOC})
TARGET_LINK_LIBRARIES(wott-server ${QT_LIBRARIES})