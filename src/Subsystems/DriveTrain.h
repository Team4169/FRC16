#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drivetrain: public Subsystem {

private:
	RobotDrive *robot;

public:
	Drivetrain(RobotDrive *drive);
	void InitDefaultCommand();
	void drive(float lSpeed, float rSpeed);
	void drive(float distance);
	void turn(float angle);

};

#endif
