#include "GameManager.h"
#include <math.h>
GameManager::GameManager()
{
}

GameManager::GameManager(std::chrono::duration<double> timestep) :timestep_{ timestep }
{
}

void GameManager::Update(PID &Regler, Ball &Ball, Rocker &Rocker)
{
	using namespace std::chrono_literals;
	Rocker.set_target_angle(Regler.control());
	Rocker.update(timestep_);

	Ball.velocity=+(9.81*sin(Rocker.get_angle())*timestep_/1000ms);//Beschleunigung
}

void GameManager::Push_Ball(Ball &Ball)
{
	Ball.velocity = +0.5;
}

void GameManager::Reset(Ball &Ball, Rocker &Rocker)
{
	Ball.velocity = 0;
	Ball.position = 0; //Oder Center, je nach implementierung
	Rocker.reset();
}
