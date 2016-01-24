#include "BridgeAuton.h"
#include "Drive\BridgeAutoDrive.h"
#include "Gate\Deploy.h"
#include "AutonDrive.h"

BridgeAuton::BridgeAuton() {
        AddSequential(new BridgeAutoDrive(-0.6, -0.6));
        AddParallel(new Deploy());
        AddSequential(new AutonDrive(0.0, 0.0));
}
