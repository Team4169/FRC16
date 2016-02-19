#include <AutonomousMode.h>
#include "WPILib.h"
#include <Subsystems/Drivetrain.h>

#include "Vector.h"
#include "XboxController.h"

#include "Subsystems/Shooter.h"
#include "Subsystems/BallCollector.h"
#include "ModeNum.h"
#include <chrono>

class Robot: public IterativeRobot {
private:
	// Input devices
	std::unique_ptr<XboxController> controller;

	// Subsystems
	std::unique_ptr<Drivetrain> drive_train;
	std::unique_ptr<Shooter> shooter;
	std::unique_ptr<BallCollector> ball_collector;

	// Chooosing an autonomous program
	SendableChooser* chooser;
	int slot_number;

	std::chrono::milliseconds ms;

	void RobotInit() {
		// Input devices
		controller = std::unique_ptr<XboxController>(new XboxController(0));

		// Subsystems
		drive_train = std::unique_ptr<Drivetrain> (new Drivetrain());
		shooter = std::unique_ptr<Shooter> (new Shooter());
		ball_collector = std::unique_ptr<BallCollector> (new BallCollector());

		// Choosing an autonomous program
		chooser = new SendableChooser();
		chooser->AddDefault("Low Bar", new AutonomousMode(0));
		chooser->AddObject("Not Low Bar", new AutonomousMode(1));
		SmartDashboard::PutData("Autonomous modes:", chooser);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit() {
	}

	void DisabledPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() {
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::system_clock::now().time_since_epoch()
		);
		slot_number = ((AutonomousMode*) chooser->GetSelected())->slotnum;
		switch(slot_number){
		case slot1: {
			break;
		}
		case slot2: {
			break;
		}
		case slot3: {
			break;
		}
		case slot4: {
			break;
		}
		case slot5: {
			break;
		}
		}
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit() {
		controller->Calibrate();
	}

	void TeleopPeriodic() {
		// Calibrate
		if(controller->GetButton(controller->ButtonRightJoystickPress)) {
			controller->Calibrate();
		}

		// Chases drive
		std::unique_ptr<Vector> left_stick_vector = std::unique_ptr<Vector>(controller->GetLeftStickVector());
		std::unique_ptr<Vector> right_stick_vector = std::unique_ptr<Vector>(controller->GetRightStickVector());

		drive_train->TankDrive(left_stick_vector->GetMagnitude(true),
							right_stick_vector->GetMagnitude(true));

		// Shooter control
		if (controller->GetRightTrigger() >= 0.5) {
			shooter->run_shooter();
		}else{
			shooter->stop_shooter();
		}

		// Ball Collector control
		if (controller->GetLeftTrigger() >= 0.5) {
			ball_collector->Start();
		} else {
			ball_collector->Stop();
		}
	}

	void TestPeriodic() {
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

