#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <tf/transform_listener.h>
#include<iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Quaternion.h>
#include <tf/transform_datatypes.h>
#include <alvar_tf/marker.h>


class Dane{
public:
    float positionx;
    float positiony;
    float positionz;
    float orientationx;
    float orientationy;
    float orientationz;
    float orientationw;

};


int main(int argc, char** argv){  

  ros::init(argc, argv, "my_tf_listener");

  ros::NodeHandle node;
  ros::NodeHandle node2;
  ros::NodeHandle node3;
  ros::NodeHandle node4;

  ros::Publisher pose_publisher = node.advertise<alvar_tf::marker>("ar_pose_marker1", 10);
  ros::Publisher pose_publisher2 = node2.advertise<alvar_tf::marker>("ar_pose_marker2", 10);
  ros::Publisher pose_publisher3 = node3.advertise<alvar_tf::marker>("ar_pose_marker3", 10);
  ros::Publisher pose_publisher4 = node4.advertise<alvar_tf::marker>("ar_pose_marker4", 10);

  Dane tab[10];
  Dane tab2[10];
  Dane tab3[10];
  Dane tab4[10];
  int licznik = 0;
  double roll, pitch, yaw;
  double roll2, pitch2, yaw2;
  double roll3, pitch3, yaw3;
  double roll4, pitch4, yaw4;

  ROS_INFO("Dziala");

  tf::TransformListener listener;
  tf::TransformListener listener2;
  tf::TransformListener listener3;
  tf::TransformListener listener4;

  alvar_tf::marker msg;
  alvar_tf::marker msg2;
  alvar_tf::marker msg3;
  alvar_tf::marker msg4;


  ros::Rate rate(10.0);


  while (node.ok()&&node2.ok()&&node3.ok()&&node4.ok()){


    ROS_INFO("Licznik: %i",licznik);

    tf::StampedTransform transform;
    tf::StampedTransform transform2;
    tf::StampedTransform transform3;
    tf::StampedTransform transform4;


    try{
      listener.lookupTransform("/usb_cam","/ar_marker_17",ros::Time(0), transform); // The reference transform is in the first place
      listener2.lookupTransform("/usb_cam","/ar_marker_11",ros::Time(0), transform2);
      listener3.lookupTransform("/usb_cam","/ar_marker_13",ros::Time(0), transform3);
      listener4.lookupTransform("/usb_cam","/ar_marker_14",ros::Time(0), transform4);

    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
    }

    /*if(listener.canTransform("/ar_marker_17","/usb_cam", ros::Time(0)) == true){
        ROS_INFO("istnieje");
    }
    else
    if(listener.canTransform("/ar_marker_17","/usb_cam", ros::Time(0)) == false){
        ROS_INFO(" nie istnieje");
    } //function that tells if such a transformation is available*/



    /*if(listener.frameExists("ar_marker_17") == true){
        ROS_INFO("istnieje");
    }
    else{
    if(listener.frameExists("ar_marker_17") == false){
        ROS_INFO("nie istnieje");
    } //a function that says if such transformation is in tf tree*/

	//conditions that are responsible for publishing zero on a topic until a marker appears in the camera's field of view
    if(listener.frameExists("ar_marker_17") == false){
        msg.pose.header.stamp = ros::Time::now();
        msg.pose.header.frame_id = "/ar_marker_17";

        msg.pose.pose.position.x = 0.0;
        msg.pose.pose.position.y = 0.0;
        msg.pose.pose.position.z = 0.0;

        msg.pose.pose.orientation.x = 0.0;
        msg.pose.pose.orientation.y = 0.0;
        msg.pose.pose.orientation.z = 0.0;
        msg.pose.pose.orientation.w = 0.0;

        msg.twist.x = 0.0;
        msg.twist.y = 0.0;
        msg.twist.z = 0.0;
    }

    if(listener.frameExists("ar_marker_11") == false){
        msg2.pose.header.stamp = ros::Time::now();
        msg2.pose.header.frame_id = "/ar_marker_11";

        msg2.pose.pose.position.x = 0.0;
        msg2.pose.pose.position.y = 0.0;
        msg2.pose.pose.position.z = 0.0;

        msg2.pose.pose.orientation.x = 0.0;
        msg2.pose.pose.orientation.y = 0.0;
        msg2.pose.pose.orientation.z = 0.0;
        msg2.pose.pose.orientation.w = 0.0;

        msg2.twist.x = 0.0;
        msg2.twist.y = 0.0;
        msg2.twist.z = 0.0;
    }

    if(listener.frameExists("ar_marker_13") == false){
        msg3.pose.header.stamp = ros::Time::now();
        msg3.pose.header.frame_id = "/ar_marker_13";

        msg3.pose.pose.position.x = 0.0;
        msg3.pose.pose.position.y = 0.0;
        msg3.pose.pose.position.z = 0.0;

        msg3.pose.pose.orientation.x = 0.0;
        msg3.pose.pose.orientation.y = 0.0;
        msg3.pose.pose.orientation.z = 0.0;
        msg3.pose.pose.orientation.w = 0.0;

        msg3.twist.x = 0.0;
        msg3.twist.y = 0.0;
        msg3.twist.z = 0.0;
     }

    if(listener.frameExists("ar_marker_14") == false){
        msg4.pose.header.stamp = ros::Time::now();
        msg4.pose.header.frame_id = "/ar_marker_14";

        msg4.pose.pose.position.x = 0.0;
        msg4.pose.pose.position.y = 0.0;
        msg4.pose.pose.position.z = 0.0;

        msg4.pose.pose.orientation.x = 0.0;
        msg4.pose.pose.orientation.y = 0.0;
        msg4.pose.pose.orientation.z = 0.0;
        msg4.pose.pose.orientation.w = 0.0;

        msg4.twist.x = 0.0;
        msg4.twist.y = 0.0;
        msg4.twist.z = 0.0;
     }

    //for marker 17:

    if(listener.frameExists("ar_marker_17") == true){
    msg.pose.header.stamp = ros::Time::now();
    msg.pose.header.frame_id = "/ar_marker_17";

    msg.pose.pose.position.x = transform.getOrigin().getX();
    msg.pose.pose.position.y = transform.getOrigin().getY();
    msg.pose.pose.position.z = transform.getOrigin().getZ();

    msg.pose.pose.orientation.x = transform.getRotation().getX();
    msg.pose.pose.orientation.y = transform.getRotation().getY();
    msg.pose.pose.orientation.z = transform.getRotation().getZ();
    msg.pose.pose.orientation.w = transform.getRotation().getW();

    tf::Quaternion q(
           msg.pose.pose.orientation.x,
           msg.pose.pose.orientation.y,
           msg.pose.pose.orientation.z,
           msg.pose.pose.orientation.w
    );

	//conversion of quaternions into degrees
    tf::Matrix3x3 m(q);
    m.getRPY(roll, pitch, yaw);
    msg.twist.x = roll*(180/M_PI);
    msg.twist.y = pitch*(180/M_PI);
    msg.twist.z = yaw*(180/M_PI);

    tab[licznik].positionx=transform.getOrigin().getX();
    ROS_INFO("Marker 17 Position x: %f",tab[licznik].positionx);

    tab[licznik].positiony=transform.getOrigin().getY();
    ROS_INFO("Marker 17 Position y: %f",tab[licznik].positiony);

    tab[licznik].positionz=transform.getOrigin().getZ();
    ROS_INFO("Marker 17 Position z: %f",tab[licznik].positionz);

    tab[licznik].orientationx=transform.getRotation().getX();
    ROS_INFO("Marker 17 Orientation x: %f",tab[licznik].orientationx);

    tab[licznik].orientationy=transform.getRotation().getY();
    ROS_INFO("Marker 17 Orientation y: %f",tab[licznik].orientationy);

    tab[licznik].orientationz=transform.getRotation().getZ();
    ROS_INFO("Marker 17 Orientation z: %f",tab[licznik].orientationz);

    tab[licznik].orientationw=transform.getRotation().getW();
    ROS_INFO("Marker 17 Orientation w: %f",tab[licznik].orientationw);

	//condition that if no marker is detectable for 5 seconds, only zeros are published on a topic
    if(tab[0].positionx==tab[1].positionx&&tab[1].positionx==tab[2].positionx&&tab[2].positionx==tab[3].positionx&&tab[3].positionx==tab[4].positionx
            &&tab[0].positiony==tab[1].positiony&&tab[1].positiony==tab[2].positiony&&tab[2].positiony==tab[3].positiony&&tab[3].positiony==tab[4].positiony){
        ROS_INFO("Nie ma markera 17 w polu widzenia");


        msg.pose.pose.position.x = 0.0;
        msg.pose.pose.position.y = 0.0;
        msg.pose.pose.position.z = 0.0;

        msg.pose.pose.orientation.x = 0.0;
        msg.pose.pose.orientation.y = 0.0;
        msg.pose.pose.orientation.z = 0.0;
        msg.pose.pose.orientation.w = 0.0;

        msg.twist.x = 0.0;
        msg.twist.y = 0.0;
        msg.twist.z = 0.0;

    }

    }
    pose_publisher.publish(msg);

    //for marker 11:

    if(listener.frameExists("ar_marker_11") == true){
    msg2.pose.header.stamp = ros::Time::now();
    msg2.pose.header.frame_id = "/ar_marker_11";

    msg2.pose.pose.position.x = transform2.getOrigin().getX();
    msg2.pose.pose.position.y = transform2.getOrigin().getY();
    msg2.pose.pose.position.z = transform2.getOrigin().getZ();

    msg2.pose.pose.orientation.x = transform2.getRotation().getX();
    msg2.pose.pose.orientation.y = transform2.getRotation().getY();
    msg2.pose.pose.orientation.z = transform2.getRotation().getZ();
    msg2.pose.pose.orientation.w = transform2.getRotation().getW();

    tf::Quaternion p(
           msg2.pose.pose.orientation.x,
           msg2.pose.pose.orientation.y,
           msg2.pose.pose.orientation.z,
           msg2.pose.pose.orientation.w
    );

    tf::Matrix3x3 m2(p);
    m2.getRPY(roll2, pitch2, yaw2);
    msg2.twist.x = roll2*(180/M_PI);
    msg2.twist.y = pitch2*(180/M_PI);
    msg2.twist.z = yaw2*(180/M_PI);

    tab2[licznik].positionx=transform2.getOrigin().getX();
    ROS_INFO("Marker 11 Position x: %f",tab2[licznik].positionx);

    tab2[licznik].positiony=transform2.getOrigin().getY();
    ROS_INFO("Marker 11 Position y: %f",tab2[licznik].positiony);

    tab2[licznik].positionz=transform2.getOrigin().getZ();
    ROS_INFO("Marker 11 Position z: %f",tab2[licznik].positionz);

    tab2[licznik].orientationx=transform2.getRotation().getX();
    ROS_INFO("Marker 11 Orientation x: %f",tab2[licznik].orientationx);

    tab2[licznik].orientationy=transform2.getRotation().getY();
    ROS_INFO("Marker 11 Orientation y: %f",tab2[licznik].orientationy);

    tab2[licznik].orientationz=transform2.getRotation().getZ();
    ROS_INFO("Marker 11 Orientation z: %f",tab2[licznik].orientationz);

    tab2[licznik].orientationw=transform2.getRotation().getW();
    ROS_INFO("Marker 11 Orientation w: %f",tab2[licznik].orientationw);


    if(tab2[0].positionx==tab2[1].positionx&&tab2[1].positionx==tab2[2].positionx&&tab2[2].positionx==tab2[3].positionx&&tab2[3].positionx==tab2[4].positionx
            &&tab2[0].positiony==tab2[1].positiony&&tab2[1].positiony==tab2[2].positiony&&tab2[2].positiony==tab2[3].positiony&&tab2[3].positiony==tab2[4].positiony){
        ROS_INFO("Nie ma markera 11 w polu widzenia");


        msg2.pose.pose.position.x = 0.0;
        msg2.pose.pose.position.y = 0.0;
        msg2.pose.pose.position.z = 0.0;

        msg2.pose.pose.orientation.x = 0.0;
        msg2.pose.pose.orientation.y = 0.0;
        msg2.pose.pose.orientation.z = 0.0;
        msg2.pose.pose.orientation.w = 0.0;

        msg2.twist.x = 0.0;
        msg2.twist.y = 0.0;
        msg2.twist.z = 0.0;

    }

    }
    pose_publisher2.publish(msg2);


    //for marker 13:
    if(listener.frameExists("ar_marker_13") == true){
    msg3.pose.header.stamp = ros::Time::now();
    msg3.pose.header.frame_id = "/ar_marker_13";

    msg3.pose.pose.position.x = transform3.getOrigin().getX();
    msg3.pose.pose.position.y = transform3.getOrigin().getY();
    msg3.pose.pose.position.z = transform3.getOrigin().getZ();

    msg3.pose.pose.orientation.x = transform3.getRotation().getX();
    msg3.pose.pose.orientation.y = transform3.getRotation().getY();
    msg3.pose.pose.orientation.z = transform3.getRotation().getZ();
    msg3.pose.pose.orientation.w = transform3.getRotation().getW();

    tf::Quaternion r(
           msg3.pose.pose.orientation.x,
           msg3.pose.pose.orientation.y,
           msg3.pose.pose.orientation.z,
           msg3.pose.pose.orientation.w
    );

    tf::Matrix3x3 m3(r);
    m3.getRPY(roll3, pitch3, yaw3);
    msg3.twist.x = roll3*(180/M_PI);
    msg3.twist.y = pitch3*(180/M_PI);
    msg3.twist.z = yaw3*(180/M_PI);

    tab3[licznik].positionx=transform3.getOrigin().getX();
    ROS_INFO("Marker 13 Position x: %f",tab3[licznik].positionx);

    tab3[licznik].positiony=transform3.getOrigin().getY();
    ROS_INFO("Marker 13 Position y: %f",tab3[licznik].positiony);

    tab3[licznik].positionz=transform3.getOrigin().getZ();
    ROS_INFO("Marker 13 Position z: %f",tab3[licznik].positionz);

    tab3[licznik].orientationx=transform3.getRotation().getX();
    ROS_INFO("Marker 13 Orientation x: %f",tab3[licznik].orientationx);

    tab3[licznik].orientationy=transform3.getRotation().getY();
    ROS_INFO("Marker 13 Orientation y: %f",tab3[licznik].orientationy);

    tab3[licznik].orientationz=transform3.getRotation().getZ();
    ROS_INFO("Marker 13 Orientation z: %f",tab3[licznik].orientationz);

    tab3[licznik].orientationw=transform3.getRotation().getW();
    ROS_INFO("Marker 13 Orientation w: %f",tab3[licznik].orientationw);


    if(tab3[0].positionx==tab3[1].positionx&&tab3[1].positionx==tab3[2].positionx&&tab3[2].positionx==tab3[3].positionx&&tab3[3].positionx==tab3[4].positionx
            &&tab3[0].positiony==tab3[1].positiony&&tab3[1].positiony==tab3[2].positiony&&tab3[2].positiony==tab3[3].positiony&&tab3[3].positiony==tab3[4].positiony){
        ROS_INFO("Nie ma markera 13 w polu widzenia");


        msg3.pose.pose.position.x = 0.0;
        msg3.pose.pose.position.y = 0.0;
        msg3.pose.pose.position.z = 0.0;

        msg3.pose.pose.orientation.x = 0.0;
        msg3.pose.pose.orientation.y = 0.0;
        msg3.pose.pose.orientation.z = 0.0;
        msg3.pose.pose.orientation.w = 0.0;

        msg3.twist.x = 0.0;
        msg3.twist.y = 0.0;
        msg3.twist.z = 0.0;

    }

    }
    pose_publisher3.publish(msg3);

    //for marker 14:
    if(listener.frameExists("ar_marker_14") == true){
    msg4.pose.header.stamp = ros::Time::now();
    msg4.pose.header.frame_id = "/ar_marker_14";

    msg4.pose.pose.position.x = transform4.getOrigin().getX();
    msg4.pose.pose.position.y = transform4.getOrigin().getY();
    msg4.pose.pose.position.z = transform4.getOrigin().getZ();

    msg4.pose.pose.orientation.x = transform4.getRotation().getX();
    msg4.pose.pose.orientation.y = transform4.getRotation().getY();
    msg4.pose.pose.orientation.z = transform4.getRotation().getZ();
    msg4.pose.pose.orientation.w = transform4.getRotation().getW();

    tf::Quaternion s(
           msg4.pose.pose.orientation.x,
           msg4.pose.pose.orientation.y,
           msg4.pose.pose.orientation.z,
           msg4.pose.pose.orientation.w
    );

    tf::Matrix3x3 m4(s);
    m4.getRPY(roll4, pitch4, yaw4);
    msg4.twist.x = roll4*(180/M_PI);
    msg4.twist.y = pitch4*(180/M_PI);
    msg4.twist.z = yaw4*(180/M_PI);

    tab4[licznik].positionx=transform4.getOrigin().getX();
    ROS_INFO("Marker 14 Position x: %f",tab4[licznik].positionx);

    tab4[licznik].positiony=transform4.getOrigin().getY();
    ROS_INFO("Marker 14 Position y: %f",tab4[licznik].positiony);

    tab4[licznik].positionz=transform4.getOrigin().getZ();
    ROS_INFO("Marker 14 Position z: %f",tab4[licznik].positionz);

    tab4[licznik].orientationx=transform4.getRotation().getX();
    ROS_INFO("Marker 14 Orientation x: %f",tab4[licznik].orientationx);

    tab4[licznik].orientationy=transform4.getRotation().getY();
    ROS_INFO("Marker 14 Orientation y: %f",tab4[licznik].orientationy);

    tab4[licznik].orientationz=transform4.getRotation().getZ();
    ROS_INFO("Marker 14 Orientation z: %f",tab4[licznik].orientationz);

    tab4[licznik].orientationw=transform4.getRotation().getW();
    ROS_INFO("Marker 14 Orientation w: %f",tab4[licznik].orientationw);


    if(tab4[0].positionx==tab4[1].positionx&&tab4[1].positionx==tab4[2].positionx&&tab4[2].positionx==tab4[3].positionx&&tab4[3].positionx==tab4[4].positionx
            &&tab4[0].positiony==tab4[1].positiony&&tab4[1].positiony==tab4[2].positiony&&tab4[2].positiony==tab4[3].positiony&&tab4[3].positiony==tab4[4].positiony){
        ROS_INFO("Nie ma markera 14 w polu widzenia");


        msg4.pose.pose.position.x = 0.0;
        msg4.pose.pose.position.y = 0.0;
        msg4.pose.pose.position.z = 0.0;

        msg4.pose.pose.orientation.x = 0.0;
        msg4.pose.pose.orientation.y = 0.0;
        msg4.pose.pose.orientation.z = 0.0;
        msg4.pose.pose.orientation.w = 0.0;

        msg4.twist.x = 0.0;
        msg4.twist.y = 0.0;
        msg4.twist.z = 0.0;

    }
    }

    pose_publisher4.publish(msg4);



    //listener.clear(); //czyści buffor

    if(licznik==5){
        licznik=5;

        for(int i=0;i<5;i++){

        tab[i].positionx=tab[i+1].positionx;
        tab[i].positiony=tab[i+1].positiony;
        tab[i].positionz=tab[i+1].positionz;
        tab[i].orientationx=tab[i+1].orientationx;
        tab[i].orientationy=tab[i+1].orientationy;
        tab[i].orientationz=tab[i+1].orientationz;
        tab[i].orientationw=tab[i+1].orientationw;

        tab2[i].positionx=tab2[i+1].positionx;
        tab2[i].positiony=tab2[i+1].positiony;
        tab2[i].positionz=tab2[i+1].positionz;
        tab2[i].orientationx=tab2[i+1].orientationx;
        tab2[i].orientationy=tab2[i+1].orientationy;
        tab2[i].orientationz=tab2[i+1].orientationz;
        tab2[i].orientationw=tab2[i+1].orientationw;

        tab3[i].positionx=tab3[i+1].positionx;
        tab3[i].positiony=tab3[i+1].positiony;
        tab3[i].positionz=tab3[i+1].positionz;
        tab3[i].orientationx=tab3[i+1].orientationx;
        tab3[i].orientationy=tab3[i+1].orientationy;
        tab3[i].orientationz=tab3[i+1].orientationz;
        tab3[i].orientationw=tab3[i+1].orientationw;

        tab4[i].positionx=tab4[i+1].positionx;
        tab4[i].positiony=tab4[i+1].positiony;
        tab4[i].positionz=tab4[i+1].positionz;
        tab4[i].orientationx=tab4[i+1].orientationx;
        tab4[i].orientationy=tab4[i+1].orientationy;
        tab4[i].orientationz=tab4[i+1].orientationz;
        tab4[i].orientationw=tab4[i+1].orientationw;

        ROS_INFO("Dla pozycji w tabeli o numerze: %i",i);


        ROS_INFO("Marker 17 Position x: %f",tab[i].positionx);
        ROS_INFO("Marker 17 Position y: %f",tab[i].positiony);
        ROS_INFO("Marker 17 Position z: %f",tab[i].positionz);
        ROS_INFO("Marker 17 Orientation x: %f",tab[i].orientationx);
        ROS_INFO("Marker 17 Orientation y: %f",tab[i].orientationy);
        ROS_INFO("Marker 17 Orientation z: %f",tab[i].orientationz);
        ROS_INFO("Marker 17 Orientation w: %f",tab[i].orientationw);


        ROS_INFO("Marker 11 Position x: %f",tab2[i].positionx);
        ROS_INFO("Marker 11 Position y: %f",tab2[i].positiony);
        ROS_INFO("Marker 11 Position z: %f",tab2[i].positionz);
        ROS_INFO("Marker 11 Orientation x: %f",tab2[i].orientationx);
        ROS_INFO("Marker 11 Orientation y: %f",tab2[i].orientationy);
        ROS_INFO("Marker 11 Orientation z: %f",tab2[i].orientationz);
        ROS_INFO("Marker 11 Orientation w: %f",tab2[i].orientationw);


        }

    }
    else{

        licznik++;
    }


    rate.sleep();

  }


  return 0;
}

