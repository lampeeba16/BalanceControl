#include "Game_manager.h"
#include "PID.h"

#include <cmath>
#include <iostream>

Game_manager::Game_manager(PID &controller) :
	controller_{ controller }
{
}

void Game_manager::update(std::chrono::duration<double> timestep)
{
	rocker_.set_target_angle(controller_.calculate(ball_.position, timestep, 0));
	rocker_.update(timestep);

	ball_.velocity += (9.81*sin(rocker_.get_angle()) * timestep.count());//Geschwindigkeit berechnen und setzen
	ball_.position += (ball_.velocity * timestep.count());//Neue Position berechnen und setzen

	//std::cout << "seas" << std::endl;

	if (abs(ball_.position) >= (rocker_.length() / 2))
		ball_down_ = 0;
	else 
		ball_down_ = 1;
		
}

void Game_manager::push_ball(double velocity)
{
	ball_.velocity += velocity;
}

void Game_manager::reset()
{
	ball_.velocity = 0;
	ball_.position = 0; //Oder Center, je nach implementierung
	rocker_.reset();
}

Ball Game_manager::ball() const
{
	return ball_;
}

Rocker Game_manager::rocker() const
{
	return rocker_;
}
