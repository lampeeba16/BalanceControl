#pragma once
//#include "stdafx.h"
#include <chrono>
#include "Ball.h"
#include "Rocker.h"
#include "PID.h"


class PID;

class GameManager
{
public:
	GameManager(PID &Regler);
	
	void update(std::chrono::duration<double> timestep);

	void push_ball(double velocity);

	void reset();

	Ball ball();

	Rocker rocker();

	//~GameManager();
private:
	PID controller_;
	Ball ball_;
	Rocker rocker_;
};
