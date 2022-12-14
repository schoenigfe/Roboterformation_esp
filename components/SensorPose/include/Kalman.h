#pragma once
#include "RosMsgsLw.h"
#include "SensorValue.h"
#include "Marvelmind.h"
//#include "freertos/FreeRTOS.h"
//#include "freertos/queue.h"
//#include "freertos/semphr.h"

class Kalman
{
    public:
		SensorValue<ros_msgs_lw::Pose2D> kalmanPose;
		Kalman(Marvelmind*);
		Kalman(Kalman const&) = delete;
		~Kalman();
	private:		
		void _kalman_task(void* pvParameters);
		void calculate_imu();
		void calculate_gps();
		static ros_msgs_lw::Pose2D pose;
		static ros_msgs_lw::PoseQual poseQual;
		static ros_msgs_lw::Imu imu;
		bool new_measurement_imu;
		bool new_measurement_gps;
		uint timestamp_imu = 0;
		uint timestamp_gps = 0;	
		uint last_timestamp_imu = 0;
		uint last_timestamp_gps = 0;
		float dt_imu;
		float dt_gps;	
	    float signal_quality;
	    float ax;
	    float ay;
	    float atheta;
	    float xy_deviation;
	    float theta_deviation;
		float rxy;
		float rxy_dot;
		float rt;
		float rt_dot;
		float acc_x;
		float acc_y;
		float gyro_z;
		float x;
		float y;
		float theta;
	    float dt;		
	    dspm::Mat A = dspm::Mat(6,6);
	    dspm::Mat B = dspm::Mat(6,6);
	    dspm::Mat H = dspm::Mat(6,6);
	    dspm::Mat P = dspm::Mat(6,6);
	    dspm::Mat Q = dspm::Mat(6,6);
	    dspm::Mat R	= dspm::Mat(6,6);
		dspm::Mat U = dspm::Mat(6,1);
		dspm::Mat Z = dspm::Mat(6,1);
		dspm::Mat X = dspm::Mat(6,1);
		dspm::Mat X_prio = dspm::Mat(6,1);
		dspm::Mat Y = dspm::Mat(6,1);
		dspm::Mat K = dspm::Mat(6,6);
};
