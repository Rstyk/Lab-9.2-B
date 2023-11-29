#include "pch.h"
#include "CppUnitTest.h"
#include "../laba 9.2 B/laba 9.2 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab92B
{
	TEST_CLASS(lab92B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 3;
			Student students[N] = {
				{ "Ivanov", 5, 4, 5, 2, Spec::йм, 0 },
				{ "Petrov", 4, 5, 3, 3, Spec::ог, 0 },
				{ "Sidorov", 5, 5, 5, 4, Spec::тк, 0 }
			};
			int result = Physics(students, N);
			Assert::AreEqual(2, result);

		}
	};
}
