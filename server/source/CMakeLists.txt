cmake_minimum_required(VERSION 2.8)
PROJECT(woot-server)
FIND_PACKAGE(Qt4 REQUIRED)

include_directories ("${PROJECT_SOURCE_DIR}/includes"
  "${PROJECT_SOURCE_DIR}/includes/event")
SET(CMAKE_CXX_FLAGS "-W -Wall -std=c++0x")

SET(wott_SOURCES src/main.cpp
  src/Boot.cpp
  src/WottApplication.cpp
  src/Log.cpp
  src/Log/Manager.cpp
  src/Log/AbstractLogger.cpp
  src/Log/StdLogger.cpp
  src/Sql.cpp
  src/Sql/Manager.cpp
  )

SET(wott_HEADERS includes/Wott.hpp
  includes/Boot.hpp
  includes/WottApplication.hpp
  includes/Log.hpp
  includes/Log/Manager.hpp
  includes/Log/AbstractLogger.hpp
  includes/Log/StdLogger.hpp
  includes/Sql.hpp
  includes/Sql/Manager.hpp
)

QT4_WRAP_CPP(wott_HEADERS_MOC ${wott_HEADERS})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})


SET(QT_USE_QTNETWORK TRUE)

ADD_EXECUTABLE(wott-server ${wott_SOURCES} 
    ${wott_HEADERS_MOC})
TARGET_LINK_LIBRARIES(wott-server ${QT_LIBRARIES})