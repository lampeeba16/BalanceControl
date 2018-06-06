#pragma once
#include "pid_test_point.h"
#include <chrono>
#include <vector>

class Optimizer
{
public:
	Optimizer(Pid_test_point start_point, int max_step_count = 100, double init_step_size = 1, double min_step_size = 1e-6);

	Pid_test_point get_optimum() const;

private:
	double error_calc(double p, double i, double d) const;
	static std::vector<Pid_test_point> get_test_points(double p_para, double i_para, double d_para, double step);

	Pid_test_point start_point_;
	int max_step_count_;
	double init_step_size_;
	double min_step_size_;
	std::chrono::milliseconds delta_t_;
	static constexpr double step_factor = .2;
};
