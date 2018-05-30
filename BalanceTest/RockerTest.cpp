#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BalanceLib/Rocker.h"
#include <chrono>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BalanceTest
{
	TEST_CLASS(Rocker_test)
	{
	public:

		TEST_METHOD(Test_Update)
		{
			Rocker r{ 2, pi / 5, pi / 10 };
			r.set_target_angle(1);
			r.update(std::chrono::milliseconds(10));

			const auto angle = r.get_angle();

			Assert::AreEqual(pi / 1000, angle, 1e-10);
		}

	private:
		static constexpr double pi = 3.14159265358979323846;
	};
}