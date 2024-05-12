// TestDll.cpp : DLL을 위해 내보낸 함수를 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "TestDll.h"
#include <math.h>
#include <stdexcept>

// 내보낸 변수의 예제입니다.
TESTDLL_API int nTestDll=0;

// 내보낸 함수의 예제입니다.
TESTDLL_API int fnTestDll(void)
{
    return 0;
}

// 내보낸 클래스의 생성자입니다.
CTestDll::CTestDll()
{
    return;
}

double CTestDll::Square(double x)
{
    // Validate parameter:
    if (x < 0.0) throw std::out_of_range("Negative input");

    double result = x;
    double diff = x;
    // old code:
    /*while (diff > result / 1000)
    {
        double oldResult = result;
        result = result - (result * result - x) / (2 * result);
        diff = fabs(oldResult - result);
    }*/
    // new code:
    while (diff > result / 1000)
    {
        double oldResult = result;
        result = (result + x / result) / 2.0;
        diff = fabs(oldResult - result);
	}
    
	return result;
}