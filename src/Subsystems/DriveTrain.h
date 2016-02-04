/*
 * DriveTrain.h
 *
 *  Created on: Feb 1, 2016
 *      Author: Benjamin
 */

#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem {

private:
	RobotDrive* robot;

public:
	DriveTrain(RobotDrive drive);
	void InitDefaultCommand();
	void drive(float lSpeed, float rSpeed);

};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
