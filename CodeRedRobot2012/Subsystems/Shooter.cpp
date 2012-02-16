#include "Shooter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/Shooter/ShootOff.h"
#include <math.h>

// Names of NetworkTable fields for PIDController
static const char *kP = "p";
static const char *kI = "i";
static const char *kD = "d";
static const char *kEnabled = "enabled";

Shooter::Shooter() : PIDSubsystem("Shooter", Kp, Ki, Kd),
					 sJagA(SHO_MTR_A),
					 sJagB(SHO_MTR_B),
					 sJagC(SHO_MTR_C),
					 sJagD(SHO_MTR_D),
					 m_enc(SHO_CNT_SPEED)
{
	double p;
	double i;
	double d;
	bool enabled;
	
	m_speed = 0;
	
	m_enc.Start();
	
	// Once tuning has been finished, these may be hard-coded
	m_prefs = Preferences::GetInstance();
	// If this is the first run, defaults of 0.0 and false will kick in
	p = m_prefs->GetDouble("SHO_P", 0.0);
	i = m_prefs->GetDouble("SHO_I", 0.0);
	d = m_prefs->GetDouble("SHO_D", 0.0);
	enabled = m_prefs->GetBoolean("SHO_PID_EN", false);
	
	// GetPIDController() returns a PIDController, which doesn't have the GetTable()
	// function we need to hook updates or to add it to the dashboard
	SendablePIDController* controller = (SendablePIDController*)GetPIDController();
	
	// Write the prefs into the PIDController
	GetPIDController()->SetPID(p, i, d);
	if (enabled) Enable();
	
	// Debugging mode:
	// Allows PID constants to be modified on the DS
	SmartDashboard::GetInstance()->PutData("Shooter PID", controller);
	// Hook updates from the Dashboard so we can save them to prefs
	controller->GetTable()->AddChangeListenerAny(this);
}
double Shooter::ReturnPIDInput() {
	// Scale speeds to 1.0 max
	// Makes jumping to manual control easier
	return m_enc.GetRate() / kMaxRate;
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new ShootOff());
}

void Shooter::Stop() {
	Output(0);
}
/* author@geoffrey.twardokus */

void Shooter::Run() {
	Output(m_speed);
}

void Shooter::Output(double speed) {
	// If PIDController is not active, run with raw speed
	if (GetPIDController()->IsEnabled()) {
		SetSetpoint(speed);
	} else {
		PIDWrite(speed);
	}
}

void Shooter::SetSpeed(double speed) {
	m_speed = speed;
	SmartDashboard::Log(m_speed, "Shooter Speed");
}

double Shooter::GetDistance() {
	double x; //Placeholder for disHeight
	double disHeight; //This is the difference between the heights of the camera and the backboard
	if(m_dis0 < m_dis1) {
		m_initialTurnAngle =  atan(((480-pointOnBBY)/(240/tan(21.5)))+pointOnBBX);			//Conversion factor to find angle. See Fig.1
		m_distHeight = x; 																	//At a later date, make x the difference between the camera height 
																							//and the backboard
		m_dis0 = ((disHeight*(cos(m_ang0))/sin(m_ang0)));									//Find the distance to the point at Kinect level directly below the
																							//first point on the backboard (m_dis0). Here we used point 0 (Fig. 2)
		
		m_dis1 = ((disHeight*(cos(m_ang1)))/sin(m_ang1));									//Find the distance to the point at Kinect level directly below the
																							//first point on the backboard (m_dis1). Here we used point 1 (Fig. 2)
		
		m_angleA = acos((4/*feet*/+(m_dis0*m_dis0)-(m_dis1*m_dis1))/(4/*feet*/*(m_dis0)));	//Find an angle, A, using Law of Cosines. THe angle is shown in Fig. 3
																							//We can do this using m_dis0, m_dis1, and the width of the vision 
																							//target.
		
		m_angleB = 180-m_angleA;															//Find the angle which is supplementary to angle A, called B.
		
		m_distAll = m_dis0*(sin(m_angleB));													//Find the distance from the robot to the wall where the alliance 
																							//station is (Fig. 4), using Law of Sines and m_dis0, angle B,
																							//and the right angle.
		
		m_distDiff = (m_distAll*(sin(m_angleB)))/sin(m_angleB);								//Find the distance from the point where m_distAll intersects the wall
																							//to the near edge of the vision target
		
		double newDistAll = m_distAll + 1.25;												//Add to m_distAll the distance the basket sticks out in order
																							//to find the distance behind the backboard that the reflection lies
		
		double distReflection;																//Distance to the reflection of the basket across the target
																							
		distReflection = sqrt((m_distDiff*m_distDiff)+(newDistAll*newDistAll));				//Use the pythagorean theorem and m_distDiff, newDistAll, and the 
																							//distance back from the board to find the distance to the reflection,
																							//distReflection.
		
		m_distance = distReflection;														//Irrelevant for this function, but this is to allow the shooter
																							//to reconcile itself
		
	} //This entire 'else' statement is simply to negate the values if the robot is on the right side of the board
	
	else if(m_dis1 < m_dis0) {
		m_initialTurnAngle =  atan(((480-pointOnBBY)/(240/tan(21.5)))+pointOnBBX);	
		m_distHeight = x; //At a later date, make x the difference between the camera height and the backboard
		m_dis0 = ((disHeight*(cos(m_ang1))/sin(m_ang1)));
		m_dis1 = ((disHeight*(cos(m_ang0)))/sin(m_ang0));
		m_angleA = acos((4/*feet*/+(m_dis1*m_dis1)-(m_dis0*m_dis0))/(4/*feet*/*(m_dis1)));
		m_angleB = 180-m_angleA;
		m_distAll = m_dis1*(sin(m_angleB));
		m_distDiff = (m_distAll*(sin(m_angleB)))/sin(m_angleB);
		m_newDistAll = m_distAll + 1.25;
		double newDistAll = m_distAll + 1.25;
		double distReflection;
		distReflection = sqrt((m_distDiff*m_distDiff)+(newDistAll*newDistAll));
		m_distance = distReflection;
		
		m_distance = m_distDiff + 1;
		
	} 
	//This block allows us to use simple math (pyth. theorem) if the distances are equal, i.e. the robot is perfectly centered
	else if(m_dis0 == m_dis1) {
		m_distance = sqrt((m_dis0*m_dis0)+1);
	}
	
	return m_distance;
}

double Shooter::SetAngle() {
	int x1;/*These represent coordinates*/
	int x2;/*of pixels from the Kinect.*/
	int x3;/*Ian (aka Techman 2.0) should*/
	int x4;/*fix this function later*/
	
	m_angle3 = atan((m_distDiff)/(m_distAll));
	m_angle4 = atan((m_distDiff)/(m_newDistAll));
	if(m_dis1 > m_dis0) {
		m_correctAngle = m_angle3 - m_angle4;
	} else if(m_dis0 > m_dis1) {
		m_correctAngle = -(m_angle3 - m_angle4);
	}
	m_returnedAngle = atan((((x1+x2+x3+x4)/4)-320)/(320/tan(28.5)));
	m_finalAngle = m_returnedAngle + m_correctAngle;
	
	return m_returnedAngle;
}

void Shooter::UsePIDOutput(double output) {
	/*Insert formula here using the predetermined distance and other variables (if needed) that determines the value of output*/
	
	sJagA.Set(output);
	sJagB.Set(output);
	sJagC.Set(-output);
	sJagD.Set(-output);
	
	SmartDashboard::Log(sJagA.GetOutputCurrent(), "Right Shooter");
	SmartDashboard::Log(sJagC.GetOutputCurrent(), "Left Shooter");
	
	SmartDashboard::Log(ReturnPIDInput(), "Gear Tooth");
}

void Shooter::ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type)
{
	// The PIDController is also listening for changes, so there is no need to push out the new settings here
	if (strcmp(name, kP) == 0 || strcmp(name, kI) == 0 || strcmp(name, kD) == 0)
	{
		// Save the settings so that they persist across reboots
		m_prefs->PutDouble("SHO_P", table->GetDouble(kP));
		m_prefs->PutDouble("SHO_I", table->GetDouble(kI));
		m_prefs->PutDouble("SHO_D", table->GetDouble(kD));
	}
	else if (strcmp(name, kEnabled) == 0)
	{
		m_prefs->PutBoolean("SHO_PID_EN", table->GetBoolean(kEnabled));
	}
}
