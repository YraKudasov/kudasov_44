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


	TEST_CLASS(RelaxationOfGraphEdgeTESTS)
	{
	public:
		TEST_METHOD(roadFromFirstToSecondCity)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, infinity},
											{infinity,infinity, 0, 3, infinity},
											{infinity,infinity, infinity, 0, 2},
											{infinity,infinity, infinity, infinity, 0} };
			int minAmountOfWay[MAX_SIZE]={ infinity, 0, infinity, infinity, infinity};
			int shortestPath[MAX_SIZE] = { infinity, 0, 0, 0, 0 };
			RelaxationOfGraphEdge(1, 2, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[2], 4);
			Assert::AreEqual(shortestPath[2], 1);

		}

		TEST_METHOD(roadFromIToJCity)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, infinity},
											{infinity,infinity, 0, 3, infinity},
											{infinity,infinity, infinity, 0, 2},
											{infinity,infinity, infinity, infinity, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, 4, infinity, infinity };
			int shortestPath[MAX_SIZE] = { infinity, 0, 1, 0, 0 };
			RelaxationOfGraphEdge(2, 3, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[3], 7);
			Assert::AreEqual(shortestPath[3], 2);

		}
		TEST_METHOD(roadFromPenultimateToLastCity)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, infinity},
											{infinity,infinity, 0, 3, infinity},
											{infinity,infinity, infinity, 0, 2},
											{infinity,infinity, infinity, infinity, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, 4, 7, infinity };
			int shortestPath[MAX_SIZE] = { infinity, 0, 1, 2, 0 };
			RelaxationOfGraphEdge(3, 4, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[4], 9);
			Assert::AreEqual(shortestPath[4], 3);

		}
		TEST_METHOD(cityNumberOutOfRange)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, infinity},
											{infinity,infinity, 0, 3, infinity},
											{infinity,infinity, infinity, 0, 2},
											{infinity,infinity, infinity, infinity, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, 4, 7, infinity };
			int shortestPath[MAX_SIZE] = { infinity, 0, 1, 2, 0 };
			RelaxationOfGraphEdge(0, 1, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[1], 0);
		}
		TEST_METHOD(ShortestWayNotInfinity)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, 5},
											{infinity,infinity, 0, 3, infinity},
											{infinity,infinity, infinity, 0, 2},
											{infinity,infinity, infinity, infinity, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, 4, 7, 9 };
			int shortestPath[MAX_SIZE] = { infinity, 0, 1, 2, 3 };
			RelaxationOfGraphEdge(1, 4, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[4], 5);
			Assert::AreEqual(shortestPath[4], 1);
		}
		TEST_METHOD(minAmountIInfinity)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, infinity},
											{infinity,infinity, 0, 3, infinity},
											{infinity,infinity, infinity, 0, 2},
											{infinity,infinity, infinity, infinity, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { infinity, 0, 1, 0, 0 };
			RelaxationOfGraphEdge(2, 3, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[3], infinity);
			Assert::AreEqual(shortestPath[3], 0);
		}
		TEST_METHOD(minAmountILessThanZero)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, infinity},
											{infinity,infinity, 0, 3, infinity},
											{infinity,infinity, infinity, 0, 2},
											{infinity,infinity, infinity, infinity, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { infinity, 0, 1, 0, 0 };
			RelaxationOfGraphEdge(2, 3, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[3], infinity);
			Assert::AreEqual(shortestPath[3], 0);
		}
		TEST_METHOD(minWaysSize)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity},
											{infinity,0, 4},
											{infinity,infinity, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity };
			int shortestPath[MAX_SIZE] = { infinity, 0, 0 };
			RelaxationOfGraphEdge(1, 2, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[2], 4);
			Assert::AreEqual(shortestPath[2], 1);
		}
		TEST_METHOD(mediumWaysSize)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity,infinity,infinity,infinity},
											{infinity,0, 4, infinity, infinity,infinity,infinity,infinity},
											{infinity,infinity, 0, 3, infinity,infinity,infinity,infinity},
											{infinity,infinity, infinity, 0, 2,infinity,infinity,infinity},
											{infinity,infinity, infinity, infinity, 0,7,infinity,infinity},
											{infinity,infinity, infinity, infinity, infinity,0,8,infinity},
											{infinity,infinity, infinity, infinity, infinity,infinity,0,10},
											{infinity,infinity, infinity, infinity, infinity,infinity,infinity,0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, 4, 7, 9,16,24,infinity };
			int shortestPath[MAX_SIZE] = { infinity, 0, 1, 2, 3,4, 5,0 };
			RelaxationOfGraphEdge(6, 7, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[7], 34);
			Assert::AreEqual(shortestPath[7], 6);
		}
		TEST_METHOD(bigWaysSize)
		{
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity,infinity,infinity,infinity,infinity,infinity,infinity},
											{infinity,0, 4, infinity, infinity,infinity,infinity,infinity,infinity,infinity,infinity},
											{infinity,infinity, 0, 3, infinity,infinity,infinity,infinity,infinity,infinity,infinity},
											{infinity,infinity, infinity, 0, 2,infinity,infinity,infinity,infinity,infinity,infinity},
											{infinity,infinity, infinity, infinity, 0,7,infinity,infinity,infinity,infinity,infinity},
											{infinity,infinity, infinity, infinity, infinity,0,8,infinity,infinity,infinity,infinity},
											{infinity,infinity, infinity, infinity, infinity,infinity,0,10,infinity,infinity,infinity},
											{infinity,infinity, infinity, infinity, infinity,infinity,infinity,0,3,infinity,infinity},
											{infinity,infinity, infinity, infinity, infinity,infinity,infinity,infinity,0,2,infinity},
											{infinity,infinity, infinity, infinity, infinity,infinity,infinity,infinity,infinity,0,1}, 
											{infinity,infinity, infinity, infinity, infinity,infinity,infinity,infinity,infinity,infinity,0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, 4, 7, 9,16,24,34, 37, 39, infinity };
			int shortestPath[MAX_SIZE] = { infinity, 0, 1, 2, 3,4, 5, 6 ,6 ,7 ,8, 0 };
			RelaxationOfGraphEdge(9, 10, ways, minAmountOfWay, shortestPath);
			Assert::AreEqual(minAmountOfWay[10], 40);
			Assert::AreEqual(shortestPath[10], 9);
		}
	};

	TEST_CLASS(DijkstrasAlgorithmTESTS)
	{
	public:

		TEST_METHOD(minGraphSize)
		{
			int countStrings = 2;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity},
											{infinity, 0, 2}, 
											{infinity, 3, 0} };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0 };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0 };

			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[2], 2);
			Assert::AreEqual(shortestPath[2], 1);
			
		}

		TEST_METHOD(mediumGraphSize)
		{
			int countStrings = 7;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity,infinity,infinity,infinity},
											{infinity,0, 4, infinity, 7,infinity,infinity,infinity},
											{infinity,4, 0, 3, infinity,infinity,2,infinity},
											{infinity,infinity, infinity, 0, 2,infinity,infinity,infinity},
											{infinity,6, infinity, infinity, 0,7,7,infinity},
											{infinity,infinity, infinity, infinity, infinity,0,8,infinity},
											{infinity,infinity, 6, infinity, 10,infinity,0,10},
											{infinity,infinity, infinity, infinity, infinity,infinity,infinity,0} };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0, 0, 0 };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0, 0, 0 };

			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[7],16);
			Assert::AreEqual(shortestPath[7], 6);
		}
		TEST_METHOD(bigGraphSize)
		{
			int countStrings = 10;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity,infinity,infinity,infinity,infinity,infinity,infinity},
											{infinity,0, 4, infinity, infinity,infinity,3,infinity,infinity,infinity,infinity},
											{infinity,infinity, 0, 3, infinity,infinity,100,infinity,10,infinity,infinity},
											{infinity,infinity, infinity, 0, 2,infinity,infinity,7,infinity,infinity,infinity},
											{infinity, 4, infinity, infinity, 0,7,infinity,infinity,infinity,4,infinity},
											{infinity,infinity, infinity, infinity, infinity,0,8,infinity,infinity,16,infinity},
											{infinity,infinity, infinity, infinity, infinity,infinity,0,10,infinity,15,infinity},
											{infinity,infinity, 30, infinity, infinity,infinity,infinity,0,3,infinity,infinity},
											{infinity,infinity, infinity, infinity, infinity,9,infinity,infinity,0,2,infinity},
											{infinity,infinity, infinity, infinity,34,infinity,infinity,6,infinity,0,1},
											{infinity,infinity, infinity, infinity, infinity,infinity,infinity,infinity,infinity,infinity,0} };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0, 0, 0 };

			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[10], 14);
			Assert::AreEqual(shortestPath[10], 9);
		}
		TEST_METHOD(priceOfWayOutOfRange)
		{
			int countStrings = 4;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, -6},
											{infinity,3, 0, 3, 4},
											{infinity,infinity, infinity, 0, infinity},
											{infinity,6, infinity, 3, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[4], 8);
			Assert::AreEqual(shortestPath[4], 2);

		}
		TEST_METHOD(notTheNthCity)
		{
			int countStrings = 3;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, 6},
											{infinity,3, 0, 3, 3},
											{infinity,2, 4, 0, infinity},
											{infinity,6, infinity, 3, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[3], 7);
			Assert::AreEqual(shortestPath[3], 2);

		}
		TEST_METHOD(cityOutOfRange)
		{
			int countStrings = -15;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, 6},
											{infinity,3, 0, 3, 3},
											{infinity,2, 4, 0, infinity},
											{infinity,6, infinity, 3, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[4], infinity);
			Assert::AreEqual(shortestPath[4], 0);

		}
		TEST_METHOD(fullGraph)
		{
			int countStrings = 4;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, 5, 6},
											{infinity,3, 0, 3, 4},
											{infinity,7, 2, 0, 3},
											{infinity,6, 15, 3, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[4],6);
			Assert::AreEqual(shortestPath[4], 1);

		}
		TEST_METHOD(fromAnyCityToAny)
		{
			int countStrings = 4;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, 6},
											{infinity,infinity, 0, 3, 4},
											{infinity,7, 2, 0, 3},
											{infinity,6, 15, 3, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[4], 6);
			Assert::AreEqual(shortestPath[4], 1);

		}
		TEST_METHOD(disconnectedCity)
		{
			int countStrings = 4;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, infinity},
											{infinity,infinity, 0, 3, 4},
											{infinity,infinity, infinity, 0, infinity},
											{infinity,6, 15, 3, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[4], 8);
			Assert::AreEqual(shortestPath[4], 2);

		}
		TEST_METHOD(graphWithoutWays)
		{
			int countStrings = 4;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,infinity, infinity, infinity, infinity},
											{infinity,infinity, infinity, infinity, infinity},
											{infinity,infinity, infinity, infinity, infinity},
											{infinity,infinity, infinity, infinity, infinity} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[4],infinity);
			Assert::AreEqual(shortestPath[4], 0);

		}
		TEST_METHOD(loop)
		{
			int countStrings = 4;
			int ways[MAX_SIZE][MAX_SIZE] = { {infinity,infinity, infinity, infinity, infinity},
											{infinity,0, 4, infinity, infinity},
											{infinity,infinity, 3, 3, 4},
											{infinity,infinity, 5, 0, infinity},
											{infinity,6, 15, 3, 0} };
			int minAmountOfWay[MAX_SIZE] = { infinity, 0, infinity, infinity, infinity };
			int shortestPath[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			int isWayUsed[MAX_SIZE] = { 0, 0, 0, 0, 0 };
			DijkstrasAlgorithm(countStrings, ways, isWayUsed, minAmountOfWay, shortestPath);

			Assert::AreEqual(minAmountOfWay[4], 8);
			Assert::AreEqual(shortestPath[4], 2);

		}
	};
}
