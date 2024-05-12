#include "pch.h"
#include "CppUnitTest.h"
#include "..\TestDll\TestDll.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			CTestDll testDll;
			// first test
			//Assert::AreEqual(
			//	// Expected value
			//	0.0,
			//	// Actual value
			//	testDll.Square(0.0),
			//	// Tolerance
			//	0.01,
			//	// Message
			//	L"Basic test failed",
			//	// Line number
			//	LINE_INFO()
			//);
			
			// second test
			for (double v = 1e-6; v < 1e6; v = v * 3.2)
			{
				double actual = testDll.Square(v*v);
				Assert::AreEqual(v, actual, v / 1000);
			}
		}
		TEST_METHOD(NegativeRangeTest)
		{
			wchar_t message[200];
			CTestDll testDll;
			for (double v = -0.1; v > -3.0; v = v - 0.5)
			{
				try
				{
					// Should raise an exception
					double result = testDll.Square(v);
					swprintf_s(message, L"No exception for input %g", v);
					Assert::Fail(message, LINE_INFO());
				}
				catch (std::out_of_range ex)
				{
					continue; // Correct exception.
				}
				catch (...)
				{
					swprintf_s(message, L"Incorrect exception for %g", v);
					Assert::Fail(message, LINE_INFO());
				}
			}
		}
	};
}
