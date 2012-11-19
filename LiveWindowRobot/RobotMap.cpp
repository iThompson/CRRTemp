
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// The following variables are automatically assigned by
// robotbuilder and will be updated the next time you export to
// Java from robot builder. Do not put any code or make any change
// in the following block or it will be lost on an update. To
// prevent this subsystem from being automatically updated, delete
// the following line.
CANJaguar* RobotMap::DRIVE_LJAGA = 0;
CANJaguar* RobotMap::DRIVE_LJAGB = 0;
CANJaguar* RobotMap::DRIVE_RJAGA = 0;
CANJaguar* RobotMap::DRIVE_RJAGB = 0;
Encoder* RobotMap::DRIVE_LENC = 0;
Encoder* RobotMap::DRIVE_RENC = 0;
LiveSolenoid* RobotMap::DRIVE_SHIFTER = 0;

void RobotMap::init() {
	// The following variables are automatically assigned by
	// robotbuilder and will be updated the next time you export to
	// Java from robot builder. Do not put any code or make any change
	// in the following block or it will be lost on an update. To
	// prevent this subsystem from being automatically updated, delete
	// the following line.
	LiveWindow* lw = LiveWindow::GetInstance();

	DRIVE_LJAGA = new CANJaguar(6);
	
	
	DRIVE_LJAGB = new CANJaguar(7);
	
	
	DRIVE_RJAGA = new CANJaguar(8);
	
	
	DRIVE_RJAGB = new CANJaguar(9);
	
	
	DRIVE_LENC = new Encoder(1, 2, 1, 3, false, Encoder::k4X);
	lw->AddSensor("Drive", "lEnc", DRIVE_LENC);
	DRIVE_LENC->SetDistancePerPulse(1.0);
        DRIVE_LENC->SetPIDSourceParameter(Encoder::kRate);
	DRIVE_RENC = new Encoder(1, 4, 1, 5, false, Encoder::k4X);
	lw->AddSensor("Drive", "rEnc", DRIVE_RENC);
	DRIVE_RENC->SetDistancePerPulse(1.0);
        DRIVE_RENC->SetPIDSourceParameter(Encoder::kRate);
	DRIVE_SHIFTER = new LiveSolenoid(1, 1);
	lw->AddActuator("Drive", "shifter", DRIVE_SHIFTER);
	

}
