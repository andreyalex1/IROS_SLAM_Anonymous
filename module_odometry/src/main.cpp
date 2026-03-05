#include <platform_odometry/platform_odometry.hpp>
#include <platform_odometry/steering_odometry.hpp>

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);


    std::shared_ptr<platform_odometry::SystemOdometry> node = std::make_shared<platform_odometry::SystemOdometry>();

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    return 0;
}