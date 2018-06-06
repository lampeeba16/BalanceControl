#include "stdafx.h"
#include "pid_test_point.h"

Pid_test_point::Pid_test_point(double p_val, double i_val, double d_val, double err_val) :
	p{ p_val }, i{ i_val }, d{ d_val }, err{err_val}
{
}

bool Pid_test_point::operator<(const Pid_test_point & other)
{
	return this->err < other.err;
}
