#pragma once
#include <chrono>

class Rocker
{
public:
	Rocker(double length = 2, double max_angle = pi / 8, double max_d_angle = pi / 32);

	void update(std::chrono::duration<double> duration);

	void reset();

	void set_target_angle(double target);

	double get_angle() const;

	double length() const;

private:
	double length_;
	double target_angle_;
	double max_angle_;
	double max_d_angle_;
	double current_angle_;
	static constexpr double pi = 3.14159265358979323846;
};
