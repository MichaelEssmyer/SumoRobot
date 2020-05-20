#include "LineSensor.h"

LineSensor::LineSensor(){}

int LineSensor::CheckState()
{
	ReadSensors();
	for(int i = 0; i < 4; i++)
		if(black[i] == 0)
			return i+1;
	return 0;
}

void LineSensor::ReadSensors()
{
	for(int i = 0; i < 4; i++)
		ReadOneSensor(i);
}

void LineSensor::ReadOneSensor(int i )
{
	pinMode(pins[i], OUTPUT);
	digitalWrite(pins[i], HIGH);
	delayMicroseconds(10);
	pinMode(pins[i], INPUT);

	long time = micros();

	while(digitalRead(pins[i]) == HIGH && micros() - time < 3000);
	
	int diff = micros()- time;

	if(diff > 2800)
		black[i] = 1;
	else
		black[i] = 0;
	
}

void LineSensorManeuver()
{
//to be implimented...
}