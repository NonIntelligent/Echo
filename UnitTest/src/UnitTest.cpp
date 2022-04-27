#include "pch.h"
#include "CppUnitTest.h"
#include <include/Echo.h>
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestingAVXInstructions)
		{
			float val = echo::fnEcho();
			Assert::IsTrue(val > 0.f);
			std::string s = "value is: " + std::to_string(val);
			Logger::WriteMessage(s.c_str());
		}
	};
}
