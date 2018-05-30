#pragma once
//#include "stdafx.h"
#include <chrono>
#include "Ball.h"
#include "Rocker.h"


class GameManager
{
public:
	GameManager();

	GameManager(std::chrono::duration<double> timestep);

	void Update(PID &Regler, Ball &Ball, Rocker &Rocker);

	void Push_Ball(Ball &Ball);

	void Reset(Ball &Ball, Rocker &Rocker);
private:
	std::chrono::duration<double> timestep_;

};