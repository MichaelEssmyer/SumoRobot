#ifndef LineSensor_h
#define LineSensor_h

#include <Arduino.h>

class LineSensor
{
private:
	byte pins[4] = {22,23,24,25};
	bool black[4];
public:
	LineSensor();
	int CheckState();
	void ReadOneSensor(int);
	void ReadSensors();
	void Maneuver();

};

#endif