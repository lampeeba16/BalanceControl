#include "GameManager.h"
#include <math.h>
#include "PID.h"

GameManager::GameManager()
{
}

GameManager::GameManager(std::chrono::duration<double> timestep): timestep_{ timestep }//Zeitstempel als parameter übergeben!
{
}

void GameManager::Update(PID &Regler, Ball &Ball, Rocker &Rocker)//Nicht jedes Mal mitübergeben!
{
	using namespace std::chrono_literals;

	Rocker.set_target_angle(Regler.Calculate(Ball));
	Rocker.update(timestep_);

	Ball.velocity += (9.81*sin(Rocker.get_angle()) * timestep_.count());//Geschwindigkeit berechnen und setzen
	Ball.position += (Ball.velocity * timestep_.count());//Neue Position berechnen und setzen


}

void GameManager::Push_Ball(Ball &Ball)
{
	Ball.velocity += 0.5;
}

void GameManager::Reset(Ball &Ball, Rocker &Rocker)
{
	Ball.velocity = 0;
	Ball.position = 0; //Oder Center, je nach implementierung
	Rocker.reset();
}
