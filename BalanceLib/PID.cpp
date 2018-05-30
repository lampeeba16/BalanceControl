#include "PID.h"

PID::PID()
{
}

PID::PID(double p_amount, double i_amount, double d_amount, double max_out_pos, double max_out_neg, double control_target, std::chrono::duration<double> integration_time, double integral) :
	p_amount_{ p_amount },
	i_amount_{ i_amount },
	d_amount_{ d_amount },
	max_out_pos_{ max_out_pos },
	max_out_neg_{ max_out_neg },
	control_target_{ control_target },
	integration_time_{ integration_time },
	integral_ {integral}
{
	pre_error_ = 0;
}

double PID::Calculate(Ball & Ball)
{
	double error = control_target_ - Ball.position;

	double pout = p_amount_ * error;

	integral_ += error * integration_time_.count();
	double iout = i_amount_ * integral_;

	double derivate = (error - pre_error_) / integration_time_.count();
	double dout = d_amount_ * derivate;

	double output= pout + iout + dout;

	if (output > max_out_pos_)
		output = max_out_pos_;
	else if (output < max_out_neg_)
		output = max_out_neg_;

	pre_error_ = error;

	return output;
}
