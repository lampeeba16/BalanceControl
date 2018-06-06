#pragma once

#include <chrono>

class PID
{
public:
	PID();

	PID(double p_amount, double i_amount, double d_amount, double max_out_pos, double max_out_neg, double control_target = 0, double integral = 0);

	double calculate(double value, std::chrono::duration<double> integration_time);

private:
	double p_amount_;
	double i_amount_;
	double d_amount_;
	double max_out_pos_;
	double max_out_neg_;
	double control_target_;
	double pre_error_;
	double integral_;
};