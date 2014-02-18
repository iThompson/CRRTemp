#include "VisionAuton.h"
#include "Acquisition/ArmLower.h"
#include "Acquisition/RollerSpin.h"
#include "Acquisition/RollerStop.h"
#include "Drive/DriveToDistance.h"
#include "Drive/JoystickAutoDrive.h"
#include "Shooter/Fire.h"
#include "BallToShooter.h"
#include "Vision/TurnLEDsOn.h"

#define TIME_TO_DRIVE 1.5 //TODO: Test potential dummy value
#define DIST_TO_WALL 3.25 //TODO: REPLACE Semi-DUMMY VALUE!!!
#define TIME_TO_WAIT 3 //TODO: Test Dummy Value

VisionAuton::VisionAuton() {
	m_hasHotGoal = false;
	AddParallel(new TurnLEDsOn(), 10); // Run LEDs until end of autonomous
	AddSequential(new ArmLower());
	AddParallel(new RollerSpin(false, false, true));
	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
	if(Robot::vision->IsGoalHot()) m_hasHotGoal = true;
//	AddSequential(new DriveToDistance(DIST_TO_WALL));
	AddParallel(new JoystickAutoDrive(0, 0));
	if(Robot::acquisition->HasBall() && !Robot::acquisition->BallReady())
		AddParallel(new BallToShooter(), .7);
	AddSequential(new WaitCommand(1));
	if(Robot::vision->IsGoalHot()) m_hasHotGoal = true; // Check for hot goal twice to give it time to settle
	if(m_hasHotGoal)
		AddSequential(new Fire(SHO_DEFAULT_GOAL, false, true));
	else 
	{
		AddSequential(new WaitCommand(TIME_TO_WAIT));
		AddSequential(new Fire(SHO_DEFAULT_GOAL, false, true));
	}
	AddSequential(new RollerStop());
}
