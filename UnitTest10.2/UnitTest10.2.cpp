#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ofstream out("test_file.txt");
			out << "a a a a a a a a a a" << endl;
			out.close();

			bool result = checkWords("test_file.txt");
			Assert::IsTrue(result);
		}
	};
}
