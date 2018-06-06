#include "GameManager.h"
#include "PID.h"

#include <cmath>

GameManager::GameManager(PID &controller) :
	controller_{ controller }
{

}

void GameManager::update(std::chrono::duration<double> timestep)//Nicht jedes Mal mitübergeben!
{
	using namespace std::chrono_literals;

	rocker_.set_target_angle(controller_.calculate(ball_.position, timestep, 0));
	rocker_.update(timestep);

	ball_.velocity += (9.81*sin(rocker_.get_angle()) * timestep.count());//Geschwindigkeit berechnen und setzen
	ball_.position += (ball_.velocity * timestep.count());//Neue Position berechnen und setzen
}

void GameManager::push_ball(double velocity)
{
	ball_.velocity += velocity;
}

void GameManager::reset()
{
	ball_.velocity = 0;
	ball_.position = 0; //Oder Center, je nach implementierung
	rocker_.reset();
}

Ball GameManager::ball()
{
	return ball_;
}

Rocker GameManager::rocker()
{
	return rocker_;
}
