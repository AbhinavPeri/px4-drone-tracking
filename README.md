I wrote this code in order to learn about the px4 api and ROS2. The end result was a ROS Node capabale of tracking a moving AprilTag. In the future, I plan on modifying the tracking to be more robust to the orientation of the drone as well, being more stable when following, and using the new px4-control-interface api to make the code simpler. I borrowed most of the code from the c++ offboard example given by PX4, modifying it to include the apriltag detection and tracking.

Installation Instructions:
- Follow the instructions for installing PX4 with ROS2: https://docs.px4.io/main/en/ros/ros2_comm.html (Choose the Gazebo Classic simulator instead of the normal Gazebo simulator)
- Install the apriltag_ros/apriltag_msgs packages into your ROS2 workspace: `git clone https://github.com/christianrauch/apriltag_ros.git`, `git clone https://github.com/christianrauch/apriltag_msgs.git`
- Clone this repository into your workspace and build

Instructions to Run:
- Run `MicroXRCEAgent udp4 -p 8888`
- Run `export PX4_SITL_WORLD=<path_to_this_repository>/worlds/apriltag.world`
- Run `make px4_sitl gazebo-classic_iris_downward_depth_camera` in the PX4 Autopilot directory
- Run ``ros2 run apriltag_ros apriltag_node --ros-args     -r image_rect:=/camera/image_raw     -r camera_info:=/camera/camera_info     --params-file `ros2 pkg prefix apriltag_ros`/share/apriltag_ros/cfg/tags_36h11.yaml``
- Run `ros2 run rtx_drone_controller offboard`

https://github.com/AbhinavPeri/px4-drone-tracking/assets/54607217/8e70d5e6-80b6-4f90-916d-60e2e9bb88f3
