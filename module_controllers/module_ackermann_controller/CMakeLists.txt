cmake_minimum_required(VERSION 3.16)
project(platform_ackermann_controller LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
set(THIS_PACKAGE_INCLUDE_DEPENDS
  controller_interface
  hardware_interface
  generate_parameter_library
  pluginlib
  rclcpp
  rclcpp_lifecycle
  realtime_tools
  std_srvs
  platform_steering_library
)

find_package(ament_cmake REQUIRED)
find_package(backward_ros REQUIRED)

foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

generate_parameter_library(platform_ackermann_controller_parameters
  src/platform_ackermann_controller.yaml
)

add_library(
  platform_ackermann_controller
  SHARED
  src/platform_ackermann_controller.cpp
)

target_compile_features(platform_ackermann_controller PUBLIC cxx_std_17)

target_include_directories(platform_ackermann_controller PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
  
target_link_libraries(platform_ackermann_controller PUBLIC
  platform_ackermann_controller_parameters)

ament_target_dependencies(platform_ackermann_controller PUBLIC ${THIS_PACKAGE_INCLUDE_DEPENDS})

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(platform_ackermann_controller PRIVATE "System_ACKERMANN_CONTROLLER_BUILDING_DLL")

pluginlib_export_plugin_description_file(
  controller_interface platform_ackermann_controller.xml)

install(
  DIRECTORY include/
  DESTINATION include/platform_ackermann_controller
)

install(
  TARGETS platform_ackermann_controller platform_ackermann_controller_parameters
  EXPORT export_System_ackermann_controller
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

ament_export_targets(export_System_ackermann_controller HAS_LIBRARY_TARGET)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
