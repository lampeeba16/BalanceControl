#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BalanceLib/PID.h"
#include <chrono>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



	TEST_CLASS(PID_test)
	{
	public:

		TEST_METHOD(PID_Test1)
		{
			PID controller{ 1, 1, 1, 1, -1 };
			Assert::AreEqual(-1, controller.calculate(1, std::chrono::milliseconds(1000), 0), 1e-10);
		}

		TEST_METHOD(PID_Test2)
		{
			PID controller{ 0.1, 0.1, 0.1, 1, -1 };
			Assert::AreEqual(-0.3, controller.calculate(1, std::chrono::milliseconds(1000), 0), 1e-10);
		}

	};
