# Install script for directory: C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/lib/Dyncall/dyncall

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/build64/lib/Dyncall/dyncall/Debug/dyncall_s.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/lib/Dyncall/dyncall/dyncall_macros.h"
    "C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/lib/Dyncall/dyncall/dyncall_config.h"
    "C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/lib/Dyncall/dyncall/dyncall_types.h"
    "C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/lib/Dyncall/dyncall/dyncall.h"
    "C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/lib/Dyncall/dyncall/dyncall_signature.h"
    "C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/lib/Dyncall/dyncall/dyncall_value.h"
    "C:/Users/x7air/Documents/Coding/BedrockEditionMod/BedrockModNative/lib/Dyncall/dyncall/dyncall_callf.h"
    )
endif()

