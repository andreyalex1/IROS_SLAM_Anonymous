cmake_minimum_required(VERSION 3.16)
project(platform_steering_library LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
set(THIS_PACKAGE_INCLUDE_DEPENDS
  platform_control_msgs
  controller_interface
  generate_parameter_library
  geometry_msgs
  hardware_interface
  nav_msgs
  pluginlib
  rclcpp
  rclcpp_lifecycle
  realtime_tools
  std_srvs
  tf2
  tf2_msgs
  tf2_geometry_msgs
  ackermann_msgs
)

find_package(ament_cmake REQUIRED)
find_package(backward_ros REQUIRED)

foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

generate_parameter_library(platform_steering_library_parameters
  src/platform_steering_library.yaml
)

add_library(
  platform_steering_library
  SHARED
  src/platform_steering_library.cpp
  src/steering_odometry.cpp
)

target_compile_features(platform_steering_library PUBLIC cxx_std_17)

target_include_directories(platform_steering_library PUBLIC
  "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include/platform_steering_library>")

target_link_libraries(platform_steering_library PUBLIC
  platform_steering_library_parameters)

ament_target_dependencies(platform_steering_library PUBLIC ${THIS_PACKAGE_INCLUDE_DEPENDS})

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(platform_steering_library PRIVATE "System_STEERING_BUILDING_DLL" "_USE_MATH_DEFINES")

install(
  DIRECTORY include/
  DESTINATION include/platform_steering_library
)

install(
  TARGETS platform_steering_library platform_steering_library_parameters
  EXPORT export_System_steering_library
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

ament_export_targets(export_System_steering_library HAS_LIBRARY_TARGET)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
