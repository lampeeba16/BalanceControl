// BalanceOptimizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../BalanceLib/GameManager.h"
#include "../BalanceLib/PID.h"
#include "pid_test_point.h"

#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>

double error_calc(double p, double i, double d, std::chrono::milliseconds delta);

int main()
{
	const auto delta_t = std::chrono::milliseconds(10);
	// TODO: put your program finding the optimal parameters for your balance control here!
	double p_para = 5;
	double i_para = 3;
	double d_para = 0;
	double step = 1;

	double last_cycle_error = error_calc(p_para, i_para, d_para, delta_t);
	std::cout << last_cycle_error << std::endl;
	//mgr.push_ball(0.5);
	for (int x=0; x<=100; x++)
	{
		std::vector<Pid_test_point> test_points;
		test_points.push_back(Pid_test_point{ p_para + step, i_para, d_para });
		test_points.push_back(Pid_test_point{ p_para - step, i_para, d_para });
		test_points.push_back(Pid_test_point{ p_para, i_para + step, d_para });
		test_points.push_back(Pid_test_point{ p_para, i_para - step, d_para });
		test_points.push_back(Pid_test_point{ p_para, i_para, d_para + step });
		test_points.push_back(Pid_test_point{ p_para, i_para, d_para - step });

		for (auto& test_point : test_points)
		{
			PID controller{ test_point.p, test_point.i, test_point.d, 1, -1 };
			GameManager mgr{ controller };
			mgr.push_ball(0.5);
			test_point.err = 0;

			for (int i = 0; i < 500; i++) {
				mgr.update(delta_t);
				//Position ist hier im Prinzip der Fehler!
				test_point.err += abs(mgr.ball().position);
				//std::cout << mgr.ball().position << "\t" << mgr.rocker().get_angle() << "\t" << mgr.rocker().get_target_angle() << "\t" << mgr.ball().velocity << "\t" << overall_error << std::endl;
			}
			mgr.push_ball(-0.5);
			for (int i = 0; i < 500; i++) {
				mgr.update(delta_t);
				//Position ist hier im Prinzip der Fehler!
				test_point.err += abs(mgr.ball().position);
				//std::cout << mgr.ball().position << "\t" << mgr.rocker().get_angle() << "\t" << mgr.rocker().get_target_angle() << "\t" << mgr.ball().velocity << "\t" << overall_error << std::endl;
			}
		}

		auto min_err = std::min_element(test_points.begin(), test_points.end());


		if (min_err->err >= last_cycle_error)
		{
			step = step / 2;
		}
		else
		{
			p_para = min_err->p;
			i_para = min_err->i;
			d_para = min_err->d;
			last_cycle_error = min_err->err;
		}

		std::cout << step << "\t" <<last_cycle_error << "\t" << p_para << "\t" << i_para << "\t" << d_para << std::endl;

		if (step <= 1e-6)
			break;

	}
	return 0;
}

double error_calc(double p, double i, double d, std::chrono::milliseconds delta)
{
	PID controller{ p, i, d, 1, -1 };
	GameManager mgr{ controller };
	mgr.push_ball(0.5);

	double error = 0;

	for (int i = 0; i < 500; i++) {
		mgr.update(delta);
		//Position ist hier im Prinzip der Fehler!
		error += abs(mgr.ball().position);
		//std::cout << mgr.ball().position << "\t" << mgr.rocker().get_angle() << "\t" << mgr.rocker().get_target_angle() << "\t" << mgr.ball().velocity << "\t" << overall_error << std::endl;
	}

	mgr.push_ball(-0.5);


	for (int i = 0; i < 500; i++) {
		mgr.update(delta);
		//Position ist hier im Prinzip der Fehler!
		error += abs(mgr.ball().position);
		//std::cout << mgr.ball().position << "\t" << mgr.rocker().get_angle() << "\t" << mgr.rocker().get_target_angle() << "\t" << mgr.ball().velocity << "\t" << overall_error << std::endl;
	}
	return error;
}