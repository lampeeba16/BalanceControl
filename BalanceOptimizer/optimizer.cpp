#include "stdafx.h"

#include "optimizer.h"
#include "../BalanceLib/PID.h"
#include "../BalanceLib/Game_manager.h"

#include <cmath>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std::chrono_literals;

Optimizer::Optimizer(Pid_test_point start_point, int max_step_count, double init_step_size, double min_step_size) :
	start_point_{ start_point }, 
	max_step_count_{ max_step_count }, 
	init_step_size_{ init_step_size }, 
	min_step_size_{ min_step_size },
	delta_t_ { 10ms }
{
}

Pid_test_point Optimizer::get_optimum() const
{
	double p_para = start_point_.p;
	double i_para = start_point_.i;
	double d_para = start_point_.d;
	double step = init_step_size_;
	double last_cycle_error = error_calc(p_para, i_para, d_para);

	for (int x = 0; x <= max_step_count_; x++)
	{
		auto test_points = get_test_points(p_para, i_para, d_para, step);

		for (auto& test_point : test_points)
		{
			test_point.err = error_calc(test_point.p, test_point.i, test_point.d);
		}

		const auto min_err = std::min_element(test_points.begin(), test_points.end());

		if (min_err->err >= last_cycle_error)
		{
			step *= step_factor;
		}
		else
		{
			p_para = min_err->p;
			i_para = min_err->i;
			d_para = min_err->d;
			last_cycle_error = min_err->err;
		}

		if (step <= min_step_size_)
			break;
	}

	return Pid_test_point{ p_para, i_para, d_para, last_cycle_error };
}

std::vector<Pid_test_point> Optimizer::get_test_points(double p_para, double i_para, double d_para, double step)
{
	std::vector<Pid_test_point> test_points;
	test_points.push_back(Pid_test_point{ p_para + step, i_para, d_para });
	test_points.push_back(Pid_test_point{ p_para - step, i_para, d_para });
	test_points.push_back(Pid_test_point{ p_para, i_para + step, d_para });
	test_points.push_back(Pid_test_point{ p_para, i_para - step, d_para });
	test_points.push_back(Pid_test_point{ p_para, i_para, d_para + step });
	test_points.push_back(Pid_test_point{ p_para, i_para, d_para - step });
	return test_points;
}

double Optimizer::error_calc(double p, double i, double d) const
{
	PID controller{ p, i, d, 1, -1 };
	Game_manager mgr{ controller };
	mgr.push_ball(1);

	double error = 0;
	for (int i = 0; i < 500; i++) {
		mgr.update(delta_t_);
		error += abs(mgr.ball().position);
	}

	mgr.push_ball(-1);

	for (int i = 0; i < 500; i++) {
		mgr.update(delta_t_);
		error += abs(mgr.ball().position);
	}

	mgr.push_ball(-3);

	for (int i = 0; i < 500; i++) {
		mgr.update(delta_t_);
		error += abs(mgr.ball().position);
	}

	mgr.push_ball(+2);

	for (int i = 0; i < 500; i++) {
		mgr.update(delta_t_);
		error += abs(mgr.ball().position);
	}
	return error;
}
