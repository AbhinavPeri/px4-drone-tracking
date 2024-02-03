I wrote this code in order to learn about the px4 api and ROS2. The end result was a ROS Node capabale of tracking a moving AprilTag. In the future, I plan on modifying the tracking to be more robust to the orientation of the drone as well as being more stable when following.

Installation Instructions:
- Follow the instructions for installing PX4 with ROS2: https://docs.px4.io/main/en/ros/ros2_comm.html (Choose the Gazebo Classic simulator instead of the normal Gazebo simulator)
- Install the apriltag_ros/apriltag_msgs packages into your ROS2 workspace: `git clone https://github.com/christianrauch/apriltag_ros.git`, `git clone https://github.com/christianrauch/apriltag_msgs.git`
- Clone this repository into your workspace and build

https://github.com/AbhinavPeri/px4-drone-tracking/assets/54607217/8e70d5e6-80b6-4f90-916d-60e2e9bb88f3

