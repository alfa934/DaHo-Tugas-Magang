#include "publisher_subscriber_server_client/server.hpp"

bool process(publisher_subscriber_server_client::Service::Request  &req,
             publisher_subscriber_server_client::Service::Response &res)
{
    res.sum = req.a + req.b;
    ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld]", (long int)res.sum);
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "server");
    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("add_two_ints_server", process);
    ROS_INFO("Ready to add two ints.");
    ros::spin();

    return 0;
}