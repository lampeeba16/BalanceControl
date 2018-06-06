#pragma once
#include <chrono>

class Rocker
{
public:
	Rocker(double length = 2, double max_angle = pi / 8, double max_d_angle = pi / 4);

	void update(std::chrono::duration<double> duration);

	void reset();

	void set_target_angle(double target);

	double get_angle() const;
	double get_target_angle() const;

	double length() const;

private:
	const double length_;
	double target_angle_;
	const double max_angle_;
	const double max_d_angle_;
	double current_angle_;
	static constexpr double pi = 3.14159265358979323846;
};
