#pragma once

#include <chrono>

class PID
{
public:
	PID();

	PID(double p_amount, double i_amount, double d_amount, double max_out_pos, double max_out_neg, double integral = 0);

	double calculate(double value, std::chrono::duration<double> integration_time, double control_target);

private:
	double p_amount_;
	double i_amount_;
	double d_amount_;
	double max_out_pos_;
	double max_out_neg_;
	double pre_error_;
	double integral_;
};