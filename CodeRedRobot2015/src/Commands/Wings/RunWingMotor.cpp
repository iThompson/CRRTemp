#include "RetractWings.h"
RunWingMotor::RunWingMotor() {
// Use requires() here to declare subsystem dependencies
// eg. requires(chassis);
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
Requires(Robot::wings);
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void RunWingMotor::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void RunWingMotor::Execute() {
}
// Make this return true when this Command no longer needs to run execute()
bool RunWingMotor::IsFinished() {
return false;
}
// Called once after isFinished returns true
void RunWingMotor::End() {
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunWingMotor::Interrupted() {
}
