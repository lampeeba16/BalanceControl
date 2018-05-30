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

		TEST_METHOD(Test_Constructor)
		{
			Rocker r{ 3, 4, 5 };

			Assert::AreEqual(3.0, r.length(), 1e-10);
			Assert::AreEqual(0, r.get_angle(), 1e-10);
		}


		TEST_METHOD(Test_Update)
		{
			Rocker r{ 2, 3, 2 };
			r.set_target_angle(2);
			r.update(std::chrono::milliseconds(1000));

			const auto angle = r.get_angle();
			Assert::AreEqual(2.0, angle, 1e-10);
		}


		TEST_METHOD(Test_Update_with_max_angle)
		{
			Rocker r{ 2, 3, 4 };
			r.set_target_angle(4);

			r.update(std::chrono::milliseconds(1000));

			const auto angle = r.get_angle();
			Assert::AreEqual(3.0, angle, 1e-10);
		}

		TEST_METHOD(Test_Update_with_max_d_angle)
		{
			Rocker r{ 2, pi / 5, pi / 10 };
			r.set_target_angle(1);
			r.update(std::chrono::milliseconds(10));

			const auto angle = r.get_angle();
			Assert::AreEqual(pi / 1000, angle, 1e-10);
		}

		TEST_METHOD(Test_Update_with_negative_angle)
		{
			Rocker r{ 2, 3, 2 };
			r.set_target_angle(-2);
			r.update(std::chrono::milliseconds(1000));

			const auto angle = r.get_angle();
			Assert::AreEqual(-2.0, angle, 1e-10);
		}

		TEST_METHOD(Test_Update_with_max_negative_angle)
		{
			Rocker r{ 2, 3, 4 };
			r.set_target_angle(-4);

			r.update(std::chrono::milliseconds(1000));

			const auto angle = r.get_angle();
			Assert::AreEqual(-3.0, angle, 1e-10);
		}

		TEST_METHOD(Test_Update_with_max_negative_d_angle)
		{
			Rocker r{ 2, pi / 5, pi / 10 };
			r.set_target_angle(-1);
			r.update(std::chrono::milliseconds(10));

			const auto angle = r.get_angle();
			Assert::AreEqual(-pi / 1000, angle, 1e-10);
		}

	private:
		static constexpr double pi = 3.14159265358979323846;
	};
}