// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Sensors.h"

#include "../RobotMap.h"
#include "math.h"

#include "../Commands/SensorRead.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Sensors::Sensors() : Subsystem("Sensors") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	tote1 = RobotMap::sensorstote1;
	tote2 = RobotMap::sensorstote2;
	tote3 = RobotMap::sensorstote3;
	tote4 = RobotMap::sensorstote4;
	tote5 = RobotMap::sensorstote5;
	bin = RobotMap::sensorscontainerSensor;

	m_index = 0;
	m_first = true;
	InitSensor(0, SR_CM(15), ADC_MAX, tote1, &(m_sensor_vals.tote1));
	InitSensor(1, SR_CM(15), ADC_MAX, tote2, &(m_sensor_vals.tote2));
	InitSensor(2, SR_CM(15), ADC_MAX, tote3, &(m_sensor_vals.tote3));
	InitSensor(3, SR_CM(15), ADC_MAX, tote4, &(m_sensor_vals.tote4));
	InitSensor(4, SR_CM(15), ADC_MAX, tote5, &(m_sensor_vals.tote5));
	InitSensor(5, LR_CM(38), LR_CM(20), bin, &(m_sensor_vals.bin));
	//sPort->SetTimeout(0);
	//packet = pdata.packet;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Sensors::InitSensor(int n, uint16_t min, uint16_t max, AnalogInput *input, bool *output) {
	sensor_t *sensor = SENSOR(n);
	sensor->sum = 0;
	sensor->input = input;
	int i;
	for(i = 0; i < SENSOR_NUMBER; i++) {
		sensor->values[i] = 0;
	}
}
    
void Sensors::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new SensorRead());
}

void Sensors::Update()
{
	int i;
	for(i = 0; i < SENSOR_NUMBER; i++) {
		sensor_t *sensor = SENSOR(i);
		sensor->sum -= sensor->values[m_index];
		int new_val = sensor->input->GetValue();
		if(!m_first || m_index != 0) {
			new_val = fmax(new_val, floor(sensor->prev * MAX_CHANGE));
			new_val = fmin(new_val, ceil(sensor->prev * 1./(MAX_CHANGE)));
		}
		sensor->sum += new_val;
		sensor->values[m_index] = new_val;
		sensor->prev = new_val;
	}
	m_index++;
	if(m_index == SENSOR_PERIOD) {
		m_index = 0;
		m_first = false;
	}

	int denominator = m_first ? m_index : SENSOR_PERIOD;
	for(i = 0; i < SENSOR_NUMBER; i++){
		sensor_t *sensor = SENSOR(i);
		int avg = sensor->sum / denominator;
		bool tmp = (avg >= sensor->min) && (avg <= sensor->max);
		*(sensor->output) = tmp;
	}
}

sensor_vals* Sensors::GetState()
{
	return &m_sensor_vals;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

