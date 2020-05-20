#include <Arduino.h>

class Sight
{
public:
	Sight();
	float distance(int analog);
	int closest(float* distances);

	// void senseOpponent();
	int findOpponent();
	// uint16_t calculateDistance(int ir);
};