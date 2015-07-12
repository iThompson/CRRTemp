#include "WPILib.h"
#include "ShotLogger.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class KitBot2011 : public SimpleRobot
{
//	CANJaguar lJagA;
//	CANJaguar lJagB;
//	CANJaguar rJagA;
//	CANJaguar rJagB;
	Joystick stick1; // only joystick
	Joystick stick2;
	Solenoid Sol1;
	Solenoid Sol2;
	Solenoid Sol3;
	Solenoid Sol4;
	Solenoid Sol5;
	ShotLogger* log;
	
	AnalogChannel dist;
	
	bool lastButton;
	
	static const double kCompMax = 5.0;
	static const double kCompMin = 0.0;	
	
	double LookUp(UINT16 distance, double compression) {
		double x = (double) distance;

		double compRatio = (compression - kCompMax) / (kCompMax - kCompMin);

		double speedSoft = (.0000009 * (x * x)) - .0003*x + 0.8793;
		double speedHard = (.0000009 * (x * x)) - .0003*x + 0.6793;

		// Merge the two values
		return speedHard + (speedSoft - speedHard) * compRatio;
	}

public:
	KitBot2011(void):
//		lJagA(2),
//		lJagB(3),
//		rJagA(4),
//		rJagB(5),	// these must be initialized in the same order
		stick1(1),
		stick2(2),
		Sol1(1),
		Sol2(2),
		Sol3(3),
		Sol4(4),
		Sol5(5),
		dist(1),
		lastButton(false)
	{
		log = ShotLogger::GetInstance();
	}
	
	void Autonomous() {
		if (DriverStation::GetInstance()->IsFMSAttached()) log->InMatch();
		
		log->Info("AUTONOMOUS START");
		
		while (IsAutonomous()) {
			Wait(0.10);
		}
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void)
	{
		log->Info("TELEOP START");
		
//		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			double distance = dist.GetVoltage() / (5.0 / 512.0);
			SmartDashboard::Log(distance, "Rangefinder distance");
			SmartDashboard::Log(dist.GetVoltage(), "Rangefinder voltage");
			
			Sol1.Set(stick1.GetRawButton(1));
			Sol2.Set(stick1.GetRawButton(2));
			Sol3.Set(stick1.GetRawButton(3));
			Sol4.Set(stick1.GetRawButton(4));
			Sol5.Set(stick1.GetRawButton(5));
			
			if (stick1.GetRawButton(6)) {
				if (!lastButton) log->Shot(stick1.GetZ(), stick2.GetZ());
				lastButton = true;
			} else {
				lastButton = false;
			}
			
			SmartDashboard::Log(((stick1.GetZ() + 1) / 2) * 2500, "Distance");
			SmartDashboard::Log(((stick2.GetZ() + 1) / 2) * 5.0, "Compression");
			SmartDashboard::Log(LookUp(stick1.GetZ() * 2500, /* stick2.GetZ() * 5.0 */ dist.GetVoltage()), "Shooter Speed");
			
//			myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
//			lJagA.Set(stick1.GetY());
//			lJagB.Set(stick1.GetY());
//			rJagA.Set(stick2.GetY());
//			rJagB.Set(stick2.GetY());
			Wait(0.010);				// wait for a motor update time
		}
	}
};

START_ROBOT_CLASS(KitBot2011);

