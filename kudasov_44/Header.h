#pragma once

#include <iostream>
#define MAX_SIZE 100
#define infinity 2147483647



/*!
������� ������ � .csv ����� � ������
\param[in] data[] ��������� �� ���� � �������� �������
\param[in/out] readDataMassive[1024] ������ ��� ���������� ���������� �� �������� �����
\param[in] sizeDataMassive ������ ������ ��� ���������� ���������� �� �������� �����
\return 0 ��� 1 � ����������� �� ���������� ������ ������� (0 - ������� ���������� �������, 1 - ������� ������)
*/
int readDataFromCsv(char* data[], char readDataMassive[1024], size_t sizeDataMassive);


/*!
��������� ���������� ������ ����� ���������
\param[in/out] array[MAX_SIZE] ������ ��� ����������
\param[in] countStrings  ���-�� ��������� � ������� 
\param[in] value ��������, ������� ����������� ������
*/
void fillArrayWithOneValue(int array[MAX_SIZE], int countStrings, int value);



/*!
���������� ����� �����
\param[in] i �����, ������ ���������� ������
\param[in] j �����, ��� ������ �������������
\param[in] ways[MAX_SIZE][MAX_SIZE] ������� ���������
\param[in/out] minAmountOfWay[MAX_SIZE] ������ ����������� ���������� ��������� �� ������� ������
*/
void RelaxationOfGraphEdge(int i, int j, int ways[MAX_SIZE][MAX_SIZE], int minAmountOfWay[MAX_SIZE]);




/*!
�������� ��������
\param[in] countStrings ���-�� �������
\param[in] ways[MAX_SIZE][MAX_SIZE] ������� ���������
\param[in/out] isWayUsed[MAX_SIZE] ������ �������������� �����
\param[in/out] minAmountOfWay[MAX_SIZE] ������ ����������� ���������� ��������� �� ������� ������
*/
void DijkstrasAlgorithm(int countStrings, int ways[MAX_SIZE][MAX_SIZE], int isWayUsed[MAX_SIZE], int minAmountOfWay[MAX_SIZE]);




/*!
������� ������ � .csv ����� � ������
\param[in/out] data[] ��������� �� ���� ��� ������ ����������
\param[in] minAmountOfWay[MAX_SIZE] ������ ����������� ���������� ��������� �� ������� ������
\param[in] num_cities ���-�� �������
\return 0 ��� 1 � ����������� �� ���������� ������ ������� (0 - ������� ���������� �������, 1 - ������� ������)
*/
int writeResultToTxt(char* data[], int minAmountOfWay[MAX_SIZE], int num_cities);