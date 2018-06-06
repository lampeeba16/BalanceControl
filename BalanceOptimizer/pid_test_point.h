#pragma once

struct Pid_test_point {
	Pid_test_point(double p_val, double i_val, double d_val, double err_val = 1e100);

	double p;
	double i;
	double d;
	double err;

	bool operator<(const Pid_test_point& other);
};
