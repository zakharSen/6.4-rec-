#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4(rec)/6.4(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int* a = new int[3];
			*a = 1;
			*(a + 1) = 1;
			*(a + 2) = 1;
			Assert::AreEqual(calcSumOfOdd(a, 3,0), 1);
			calcSumOfOdd(a, 3,0);
		}
	};
}
