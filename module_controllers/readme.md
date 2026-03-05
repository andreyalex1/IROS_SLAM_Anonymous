# System_controllers

## Structure

System_controllers package contains of several quasi independant modules. For now it's:

- platform_ackermann_controller
- platform_control_msgs
- platform_steering_library

### platform_ackermann_controller

platform_ackermann_controller is a frontend which inherited from platform_steering_library. It providing high level function to setup the controller.

### platform_control_msgs

platform_control_msgs is a package that provide description for custom message that used for debugging.

### platform_steering_library

platform_steering_library is one of the most complex part of the platform_controller package. It provide function to calculate odometry
in several manner (open loop, directly from commands on dc motors).
