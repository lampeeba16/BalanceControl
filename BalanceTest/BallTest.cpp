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
			const Ball ball{};
			Assert::AreEqual(0.0, ball.position, 1e-10);
			Assert::AreEqual(0.0, ball.velocity, 1e-10);
		}
	};
}