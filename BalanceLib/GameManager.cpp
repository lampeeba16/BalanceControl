#include "GameManager.h"
#include "Ball.h"

GameManager::GameManager()
{
}

GameManager::GameManager(int timestep) :timestep_{ timestep }
{
}

void GameManager::Update(PID &Regler, Ball &Ball, Rocker &Rocker)
{
	Regler.control()
}

void GameManager::Push_Ball(Ball &Ball)
{
	Ball.velocity_ = +0.5;
}

void GameManager::Reset(Ball &Ball, Rocker &Rocker)
{
	Ball.velocity_ = 0;
	Ball.Position_ = 0; //Oder Center, je nach implementierung
	Rocker.Reset_angle();
}
