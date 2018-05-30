// BalanceOptimizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../BalanceLib/GameManager.h"
#include "../BalanceLib/PID.h"

#include <iostream>
#include <chrono>


int main()
{
	// TODO: put your program finding the optimal parameters for your balance control here!
	GameManager mgr{std::chrono::milliseconds(10)};
	Ball b{};
	PID controller{ 1, 0, 3, 1, -1, 0, std::chrono::milliseconds(10), 0 };
	Rocker r;
	mgr.Push_Ball(b);
	for (int i = 0; i < 500; i++) {
		mgr.Update(controller, b, r);
		std::cout << b.position << std::endl;
	}
    return 0;
}

