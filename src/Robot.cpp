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

	float distance1[5] = {22.20244104688751*12, 24.60806716851051*12, 17.39119351980729*12, 18.61805812566858*12, 25.83493649053858*12};
	float angle1[5] = {0, 0, -M_PI/6, M_PI/6, 0};
	float distance2[5] = {0, 0, 12*25/3, 12*25/3, 0};
	float angle2[5] = {M_PI/3, M_PI/3, M_PI/2, -M_PI/2, -M_PI/3};

	void RobotInit() {
		// Input devices
		controller = std::unique_ptr<XboxController>(new XboxController(0));

		// Subsystems
		drive_train = std::unique_ptr<Drivetrain> (new Drivetrain());
		shooter = std::unique_ptr<Shooter> (new Shooter());
		ball_collector = std::unique_ptr<BallCollector> (new BallCollector());

		// Choosing an autonomous program
		chooser = new SendableChooser();
		chooser->AddDefault("Slot 1", new AutonomousMode(0));
		chooser->AddObject("Slot 2", new AutonomousMode(1));
		chooser->AddObject("Slot 3", new AutonomousMode(2));
		chooser->AddObject("Slot 4", new AutonomousMode(3));
		chooser->AddObject("Slot 5", new AutonomousMode(4));
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

		slot_number = ((AutonomousMode*) chooser->GetSelected())->slotnum;
		drive_train->DriveDistance(distance1[slot_number]);
		drive_train->TurnAngle(angle1[slot_number]);
		drive_train->DriveDistance(distance2[slot_number]);
		drive_train->TurnAngle(angle2[slot_number]);
		shooter->run_shooter();
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now().time_since_epoch()
		);
		while (!ms.count()+500<std::chrono::system_clock::now().time_since_epoch().count()){
			//waits for 500 ms
		}
		ball_collector->Start();
		while (!ms.count()+1000<std::chrono::system_clock::now().time_since_epoch().count()){
			//waits for 1000 ms
		}
		ball_collector->Stop();
		shooter->stop_shooter();
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

