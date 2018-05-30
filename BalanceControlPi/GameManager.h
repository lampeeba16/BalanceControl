#pragma once
//#include "stdafx.h"

class GameManager
{
public:
	GameManager();

	GameManager(int timestep);

	void Update(PID &Regler, Ball &Ball, Rocker &Rocker);

	void Push_Ball(Ball &Ball);

	void Reset(Ball &Ball, Rocker &Rocker);
private:
	int timestep_;


};