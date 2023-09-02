# Some Command Lines I Used To Start With ROS
  + To create a directory:

         mkdir -p ~/Catkin_works/src 
  + To change the current directory:

         cd Catkin_works
  + To create a directories and run cmake commands:

         catkin_make
  + To list directory contents of files:

         ls
  + To source the setup.bash files:

         source devel/setup.bash
  + To create a package:

         catkin_create_pkg package_name std_msgs rospy roscpp
  + To change nodes mode to executable:

         chmod a+x file_name
  + To run ROS master:

         roscore
  + To run nodes:

         rosrun package_name file_name
    
       
      
