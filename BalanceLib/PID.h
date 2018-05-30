#pragma once

#include <math.h>
#include "Ball.h"

class PID
{
public:
	PID();

	PID(double p_amount,double i_amount,double d_amount,double max_out_pos,double max_out_neg,double control_target,double max_in_pos, double max_in_neg);

	double Calculate(Ball &Ball);

private:
	double p_amount_;
	double i_amount_;
	double d_amount_;
	double max_out_pos_;
	double max_out_neg_;
	double control_target_;
	double max_in_pos_;
	double max_in_neg_;
};