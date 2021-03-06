// BalanceOptimizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "optimizer.h"
#include <algorithm>

int main()
{
	srand(time(nullptr));
	std::vector<Pid_test_point> optima;

	std::cout << "[";
	for(int x = 0; x < 100; x++)
	{
		const auto p = (rand() % 100) / 50.0;
		const auto i = (rand() % 100) / 100.0;
		const auto d = (rand() % 100) / 50.0;
		const Pid_test_point start_point{ p, i, d };
		Optimizer o{ start_point };
		optima.push_back(o.get_optimum());
		std::cout << "=";
	}
	std::cout << "]\n";

	const auto optimum = std::min_element(optima.begin(), optima.end());
	std::cout << "Optimum found with p=" << optimum->p << ", i=" << optimum->i << ", d=" << optimum->d << "(err: " << optimum->err << ")\n";
	getchar();
	return 0;
}

