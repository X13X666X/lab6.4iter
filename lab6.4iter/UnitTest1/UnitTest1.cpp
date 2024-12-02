#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include <iostream>
#include "../6.4iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayTests
{
    TEST_CLASS(ArrayFunctionTests)
    {
    public:

        // Test for CountZeroElements
        TEST_METHOD(CountZeroElements_Test)
        {
            double array[] = { 1.5, 0.0, 3.0, 0.0, 2.5 };
            int size = sizeof(array) / sizeof(array[0]);
            int result = CountZeroElements(array, size);
            Assert::AreEqual(2, result);  // There are 2 zero elements in the array
        }

        // Test for SumAfterMin
        TEST_METHOD(SumAfterMin_Test)
        {
            double array[] = { 5.0, 2.0, 3.0, 1.0, 4.0 };
            int size = sizeof(array) / sizeof(array[0]);
            double result = SumAfterMin(array, size);
            Assert::AreEqual(4.0, result, 0.001);  // Sum after the minimum element (index 3) is just 4.0
        }

        // Test for SortOddIndicesByAbs
        TEST_METHOD(SortOddIndicesByAbs_Test)
        {
            double array[] = { 2.0, -1.5, 3.0, -4.0, 5.0 };
            int size = sizeof(array) / sizeof(array[0]);
            SortOddIndicesByAbs(array, size);

            // After sorting the odd indices (1, 3), the array should become: [2.0, -1.5, 3.0, -4.0, 5.0]
            double expected[] = { 2.0, -1.5, 3.0, -4.0, 5.0 };

            for (int i = 0; i < size; ++i)
            {
                Assert::AreEqual(expected[i], array[i], 0.001);
            }
        }

    };
}
