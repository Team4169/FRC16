#include "BallCollector.h"
#include "../RobotMap.h"

BallCollector::BallCollector(): Subsystem("BallCollector") {
	motor = std::unique_ptr<Talon>(new Talon(RobotMap::INTAKE_MOTOR));
}

void BallCollector::Start() {
	motor->Set(1);
}
void BallCollector::Stop() {
	motor->Set(0);
}
BallCollector::~BallCollector(){

}
