#include <Subsystems/Drivetrain.h>
#include "../RobotMap.h"

Drivetrain::Drivetrain(): Subsystem("Drivetrain") {
	// Motors init
	left_primary_motor = std::shared_ptr<CANTalon> (new CANTalon(RobotMap::LEFT_PRIMARY_MOTOR));
	left_secondary_motor = std::shared_ptr<CANJaguar> (new CANJaguar(RobotMap::LEFT_SECONDARY_MOTOR));

	right_primary_motor = std::shared_ptr<CANTalon> (new CANTalon(RobotMap::RIGHT_PRIMARY_MOTOR));
	right_secondary_motor = std::shared_ptr<CANJaguar> (new CANJaguar(RobotMap::RIGHT_SECONDARY_MOTOR));

	// Motors sync groups
	left_primary_motor->Set(0, LEFT_SYNC_GROUP);
	left_secondary_motor->Set(0, LEFT_SYNC_GROUP);

	right_primary_motor->Set(0, RIGHT_SYNC_GROUP);
	right_primary_motor->Set(0, RIGHT_SYNC_GROUP);

	// Robot Drive init
	robot_drive = std::shared_ptr	<RobotDrive>(
			new RobotDrive(left_primary_motor, left_secondary_motor,
							right_primary_motor, right_secondary_motor)
	);
}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Drivetrain::TankDrive(float lSpeed, float rSpeed) {
	//should be constantly getting speed inputs from the controller
	robot_drive->TankDrive(lSpeed, rSpeed, true);
}

void Drivetrain::ArcadeDrive(float magnitude, float rotate) {
	robot_drive->ArcadeDrive(magnitude, rotate, true);
}

void Drivetrain::DriveDistance(float distance) {
	//left_primary_motor->GetEncVel() * left_primary_motor->GetNativeUnitsPerRotationScalar(CANTalon::FeedbackDevice::QuadEncoder);
}
