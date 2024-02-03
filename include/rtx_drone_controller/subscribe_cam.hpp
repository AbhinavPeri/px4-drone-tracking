#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
using std::placeholders::_1;

class ImageSubscriber : public rclcpp::Node
{
	public:
		ImageSubscriber() : Node("image_subscriber") {}
	
	private:
		rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
		void camera_callback(const sensor_msgs::msg::Image::SharedPtr msg) const {}
};