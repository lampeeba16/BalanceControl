#include "Rocker.h"

Rocker::Rocker(double length, double max_angle, double max_d_angle) :
	target_angle_{0},
	max_angle_{max_angle},
	max_d_angle_{max_d_angle},
	current_angle_{0}
{
}

void Rocker::update(std::chrono::duration<double> duration)
{
	double delta_angle = current_angle_ - target_angle_;
	const double max_delta = max_d_angle_ * duration.count();
	if (delta_angle > max_delta)
		delta_angle = max_delta;
	if (delta_angle < -max_delta)
		delta_angle = -max_delta;

	current_angle_ += delta_angle;
}

void Rocker::reset()
{
	target_angle_ = 0;
	current_angle_ = 0;
}

void Rocker::set_target_angle(double target)
{
	if (target > max_angle_)
		target_angle_ = max_angle_;
	else if (target < -max_angle_)
		target_angle_ = -max_angle_;
	else 
		target_angle_ = target;
}

double Rocker::get_angle() const
{
	return current_angle_;
}
