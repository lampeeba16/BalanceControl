#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BalanceLib/Ball.h"
#include <chrono>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BalanceTest
{
	TEST_CLASS(Ball_test)
	{
	public:

		TEST_METHOD(Test_Creation)
		{
			const Ball ball;
			Assert::AreEqual(0.0, ball.position, 1e-10);
			Assert::AreEqual(0.0, ball.velocity, 1e-10);
		}

		TEST_METHOD(Test_Constructor_with_parameter)
		{
			const Ball ball{2};
			Assert::AreEqual(2.0, ball.position, 1e-10);
			Assert::AreEqual(0.0, ball.velocity, 1e-10);
		}

		TEST_METHOD(Test_Constructor_with_parameters)
		{
			const Ball ball{ 2, 3 };
			Assert::AreEqual(2.0, ball.position, 1e-10);
			Assert::AreEqual(3.0, ball.velocity, 1e-10);
		}
	};
}