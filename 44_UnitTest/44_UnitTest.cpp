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
		TEST_METHOD(inputFileIsMissing)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input4.txt", NULL };
			char readDataMassive[1024]={0};
			size_t sizeDataMassive = sizeof(readDataMassive);
			int result = readDataFromCsv(data, readDataMassive, sizeDataMassive);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(inputFileIsEmpty)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input5.txt", NULL };
			char readDataMassive[1024]={0};
			size_t sizeDataMassive = sizeof(readDataMassive);
			int result = readDataFromCsv(data, readDataMassive, sizeDataMassive);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(inputFileNULL)
		{
			char readDataMassive[1024] = { 0 };
			size_t sizeDataMassive = sizeof(readDataMassive);
			int result = readDataFromCsv(NULL, readDataMassive, sizeDataMassive);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(readFileIsNonzero)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input2.txt", NULL };
			char readDataMassive[1024] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
			size_t sizeDataMassive = sizeof(readDataMassive);
			int result = readDataFromCsv(data, readDataMassive, sizeDataMassive);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(readFileOfNonFixedLength)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input2.txt", NULL };
			char* readDataMassive = "dgdfgdgd";
			int result = readDataFromCsv(data, readDataMassive, sizeof(readDataMassive));
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(readFileNULL)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input2.txt", NULL };
			int result = readDataFromCsv(data, NULL, 1024);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(readFileLessThanInputFile)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input2.txt", NULL };
			char readDataMassive[20] = { 0 };
			size_t sizeDataMassive = sizeof(readDataMassive);
			int result = readDataFromCsv(data, readDataMassive, sizeDataMassive);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(readMassiveSizeZero)
		{
			char* data[] = { "E:/2course/2cem/KiNPO/rep/input2.txt", NULL };
			char readDataMassive[1024] = { 0 };
			int result = readDataFromCsv(data, readDataMassive, 0);
			Assert::AreEqual(1, result);
		}

	};

	TEST_CLASS(fillArrayWithOneValueTESTS)
	{
	public:

		TEST_METHOD(NumberOfRowsInTheRange)
		{
			
				const int countStrings = 5;
				const int value = 42;
				int array[MAX_SIZE];

				fillArrayWithOneValue(array, countStrings, value);

				for (int i = 1; i <= countStrings; i++) {
					Assert::AreEqual(array[i], value);
				}
			
		}
		
		TEST_METHOD(NumberOfRowsToLeftOfRange)
		{

			const int countStrings = 0;
			const int value = 42;
			int array[MAX_SIZE];

			fillArrayWithOneValue(array, countStrings, value);

			for (int i = 1; i <= countStrings; i++) {
				Assert::AreNotEqual(array[i], value);
			}

		}

		TEST_METHOD(NumberOfRowsToRightOfRange)
		{

			const int countStrings = 120;
			const int value = 42;
			int array[MAX_SIZE];

			fillArrayWithOneValue(array, countStrings, value);

			for (int i = 1; i <= countStrings; i++) {
				Assert::AreNotEqual(array[i], value);
			}

		}
		TEST_METHOD(Value1)
		{

			const int countStrings = 1;
			const int value = 42;
			int array[MAX_SIZE];

			fillArrayWithOneValue(array, countStrings, value);

			for (int i = 1; i <= countStrings; i++) {
				Assert::AreEqual(array[i], value);
			}

		}
		TEST_METHOD(maxValue)
		{

			const int countStrings = MAX_SIZE - 1;
			const int value = 42;
			int array[MAX_SIZE];

			fillArrayWithOneValue(array, countStrings, value);

			for (int i = 1; i <= countStrings; i++) {
				Assert::AreEqual(array[i], value);
			}
		}
		TEST_METHOD(initializedArray)
		{

			const int countStrings = 5;
			const int value = 42;
			int array[MAX_SIZE]={3, 5, 7, 8, 23, 555};

			fillArrayWithOneValue(array, countStrings, value);

			for (int i = 1; i <= countStrings; i++) {
					Assert::AreEqual(array[i], value);
			}
		}
		TEST_METHOD(nullArray)
		{

			const int countStrings = 5;
			const int value = 42;
			int array[MAX_SIZE] = {0};

			fillArrayWithOneValue(array, countStrings, value);

			for (int i = 1; i <= countStrings; i++) {
				Assert::AreEqual(array[i], value);
			}
		}
		
	};
}
