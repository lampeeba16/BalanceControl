#include "PID.h"

PID::PID()
{
}

PID::PID(double p_amount, double i_amount, double d_amount, double max_out_pos, double max_out_neg, double control_target, double max_in_pos, double max_in_neg):p_amount_{ p_amount }, i_amount_{i_amount}, d_amount_ {d_amount}, max_out_pos_ {max_in_pos}, max_out_neg_ {max_out_neg}, control_target_{control_target}, max_in_pos_{max_in_pos}, max_in_neg_{max_in_neg}
{

}

double PID::Calculate(Ball & Ball)
{

	return 0.0;
}
