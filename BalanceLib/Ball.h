#pragma once

struct Ball
{
	Ball(double pos = 0, double vel = 0) : position{pos}, velocity{vel}
	{}

	double position;
	double velocity;
};
