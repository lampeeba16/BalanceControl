#pragma once
//#include "stdafx.h"
#include <chrono>
#include "Ball.h"
#include "Rocker.h"
#include "PID.h"


class PID;

class Game_manager
{
public:
	Game_manager(PID &controller);
	
	void update(std::chrono::duration<double> timestep);

	void push_ball(double velocity);

	void reset();

	Ball ball() const;

	Rocker rocker() const;

	bool ball_down_;

private:
	PID controller_;
	Ball ball_;
	Rocker rocker_;
};
