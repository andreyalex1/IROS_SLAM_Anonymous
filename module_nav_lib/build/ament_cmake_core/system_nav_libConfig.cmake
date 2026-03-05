# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_System_nav_lib_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED platform_nav_lib_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(platform_nav_lib_FOUND FALSE)
  elseif(NOT platform_nav_lib_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(platform_nav_lib_FOUND FALSE)
  endif()
  return()
endif()
set(_System_nav_lib_CONFIG_INCLUDED TRUE)

# output package information
if(NOT platform_nav_lib_FIND_QUIETLY)
  message(STATUS "Found platform_nav_lib:  (${platform_nav_lib_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'platform_nav_lib' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${platform_nav_lib_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(platform_nav_lib_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${platform_nav_lib_DIR}/${_extra}")
endforeach()
