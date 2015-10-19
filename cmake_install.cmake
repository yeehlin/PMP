# Install script for directory: D:/Toolkits/VTK/Examples/PMP

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Program Files/PMP")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMP/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPDemoVersion3.0/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/MFCDlgWithTabctrl/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/MFCDlgWithTabctrlOPTMatn/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/VTKShowBMP/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPVisualization/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/VTKMFCCreateBMPActors/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPMFCVisual/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPFileViewer/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPCall/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPCallConsole/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/RECYCLE/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPCreateProcess/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/MFCTextView/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPFileManage/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPMyFileViewer/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPImageProcess/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPCUDABaseVTK/cmake_install.cmake")
  INCLUDE("D:/Toolkits/VTK/Examples/PMP/PMPWindowsClientMFC/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "D:/Toolkits/VTK/Examples/PMP/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "D:/Toolkits/VTK/Examples/PMP/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
