// BalanceOptimizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../BalanceLib/GameManager.h"
#include "../BalanceLib/PID.h"

#include <iostream>
#include <chrono>


int main()
{
	const auto delta_t = std::chrono::milliseconds(10);
	// TODO: put your program finding the optimal parameters for your balance control here!
	PID controller{ 1, 0, 2, 1, -1 };
	GameManager mgr{controller};
	mgr.push_ball();
	for (int i = 0; i < 500; i++) {
		mgr.update(delta_t);
		std::cout << mgr.ball().position << "\t" << mgr.rocker().get_angle() << "\t" << mgr.rocker().get_target_angle() << "\t" << mgr.ball().velocity << std::endl;
	}
    return 0;
}

