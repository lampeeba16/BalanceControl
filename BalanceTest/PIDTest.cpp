#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BalanceLib/PID.h"
#include <chrono>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BalanceTest
{
	TEST_CLASS(PID_test)
	{
	public:

		TEST_METHOD(PID_Test1)
		{
			PID controller{ 1, 1, 1, 1, -1 };
			Assert::AreEqual(0.0, controller_.calculate(ball_.position, timestep, 0), 1e-10);
			Assert::AreEqual(0.0, ball.velocity, 1e-10);
		}

	};
}