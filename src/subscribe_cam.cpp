#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
using std::placeholders::_1;

class ImageSubscriber : public rclcpp::Node
{
	public:
		ImageSubscriber() : Node("image_subscriber")
		{
			count_ = 0;
			subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
				"/camera/image_raw", 10, std::bind(&ImageSubscriber::camera_callback, this, _1)
			);
		}
	
	private:
		rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
		int count_;
		void camera_callback(const sensor_msgs::msg::Image::SharedPtr msg)
		{
			RCLCPP_INFO(this->get_logger(), "Camera Message Received: '%d', '%d'", count_, msg->header.stamp.sec);
			count_ ++;
		}

};

int main(int argc, char *argv[])
{
	std::cout << "Starting camera subscriber node..." << std::endl;
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<ImageSubscriber>());
	
	rclcpp::shutdown();
	return 0;
}