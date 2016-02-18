#include <AutonomousMode.h>
#include "WPILib.h"
#include "XboxController.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/BallCollector.h"
#include "ModeNum.h"
#include <chrono>

class Robot: public IterativeRobot {
private:
	// Robot
	std::unique_ptr<RobotDrive> robot_drive;

	// Input devices
	std::unique_ptr<XboxController> controller;

	// Subsystems
	std::unique_ptr<Shooter> shooter;
	std::unique_ptr<BallCollector> ball_collector;

	// Chooosing an autonomous program
	SendableChooser* chooser;
	int slot_number;

	std::chrono::milliseconds ms;

	void RobotInit() {
		// Robot
		robot_drive = std::unique_ptr<RobotDrive> (new RobotDrive(1,2,3,4));

		// Input devices
		controller = std::unique_ptr<XboxController>(new XboxController(0));

		// Subsystems
		shooter = std::unique_ptr<Shooter> (new Shooter());
		ball_collector = std::unique_ptr<BallCollector> (new BallCollector());

		// Choosing an autonomous program
		chooser = new SendableChooser();
		chooser->AddDefault("Low Bar", new AutonomousMode(0));
		chooser->AddObject("Not Low Bar", new AutonomousMode(1));
		SmartDashboard::PutData("Autonomous modes:", chooser);
	}

	void DisabledInit() {
	}

	void DisabledPeriodic() {

	}

	void AutonomousInit() {
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::system_clock::now().time_since_epoch()
		);
		slot_number = ((AutonomousMode*) chooser->GetSelected())->slotnum;
		switch(slot_number){
		case slot1: {

		}
		case slot2: {

		}
		case slot3: {

		}
		}

	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {

	}

	void TeleopPeriodic() {
		// Chases drive
		std::unique_ptr<Vector> left_stick_vector = std::unique_ptr<Vector>(controller->GetLeftVector());
		std::unique_ptr<Vector> right_stick_vector = std::unique_ptr<Vector>(controller->GetRightVector());

		robot_drive->TankDrive(left_stick_vector->magnitude, right_stick_vector->magnitude, false);

		// Shooter control
		if (controller->GetTrigger(controller->RightTrigger,controller->RightTriggerOffset) >= 0.5) {
			shooter->run_shooter();
		} else {
			shooter->stop_shooter();
		}

		// Ball Collector control
		if (controller->GetTrigger(controller->LeftTrigger,controller->LeftTriggerOffset) >= 0.5) {
			ball_collector->Start();
		} else {
			ball_collector->Stop();
		}
	}

	void TestPeriodic() {

	}
};

START_ROBOT_CLASS(Robot)

