#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_6/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace QueueTest
{
	TEST_CLASS(QueueTest)
	{
	public:
        TEST_METHOD(TestCompareQueuesEqual)
        {
            // Arrange
            queue<string> q1;
            queue<string> q2;

            q1.push("Hello");
            q1.push("world");
            q1.push("!");

            q2.push("Hello");
            q2.push("world");
            q2.push("!");

            // Act
            bool equal = compareQueues(q1, q2);

            // Assert
            Assert::IsTrue(equal);
        }
	};
}