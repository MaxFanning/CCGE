#include "stdafx.h"
#include "CppUnitTest.h"

#include <Math/Inc/CMath.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CCGE::CMath;

namespace MathTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Vector3Addition)
		{
			CCGE::CMath::Vector3 a{ 0.0f, 1.0f, 0.0f };
			CCGE::CMath::Vector3 b{ 1.0f, 0.0f, 1.0f };
			CCGE::CMath::Vector3 c = a + b;
			Assert::IsTrue(c.x == 1.0f);
			Assert::IsTrue(c.y == 1.0f);
			Assert::IsTrue(c.z == 1.0f);
		}

	};
}