#include "pch.h"
#include "CppUnitTest.h"
#include "../kudasov_44/Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My44UnitTest
{
	TEST_CLASS(readDataFromCsvTESTS)
	{
	public:
		
		TEST_METHOD(allParametersAreCorrect)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input2.txt", NULL };
			char readDataMassive[1024]={0};
			size_t sizeDataMassive = sizeof(readDataMassive);
			int result = readDataFromCsv(data, readDataMassive, sizeDataMassive);
			Assert::AreEqual(0, result);
		}
		TEST_METHOD(InputFileIsMissing)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input4.txt", NULL };
			char readDataMassive[1024]={0};
			size_t sizeDataMassive = sizeof(readDataMassive);
			int result = readDataFromCsv(data, readDataMassive, sizeDataMassive);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(InputFileIsEmpty)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input3.txt", NULL };
			char readDataMassive[1024]={0};
			size_t sizeDataMassive = sizeof(readDataMassive);
			int result = readDataFromCsv(data, readDataMassive, sizeDataMassive);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(h)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input2.txt", NULL };
			char readDataMassive[1024] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
			size_t sizeDataMassive = sizeof(readDataMassive);
			int result = readDataFromCsv(data, readDataMassive, sizeDataMassive);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(h1)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input2.txt", NULL };
			char* readDataMassive = "dgdfgdgd";
			int result = readDataFromCsv(data, readDataMassive, sizeof(readDataMassive));
			Assert::AreEqual(1, result);
		}


	};
}
