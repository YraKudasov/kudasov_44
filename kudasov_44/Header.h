#pragma once

#include <iostream>
#define MAX_SIZE 100
#define infinity 2147483647



/*!
Считать данные с .csv файла в строку
\param[in] data[] Указатель на файл с входными данными
\param[in/out] readDataMassive[1024] Строка для считывания информации со входного файла
\param[in] sizeDataMassive Размер строки для считывания информации со входного файла
\return 0 или 1 в зависимости от результата работы функции (0 - функция отработала успешно, 1 - поймана ошибка)
*/
int readDataFromCsv(char* data[], char readDataMassive[1024], size_t sizeDataMassive);


/*!
Заполнить одномерный массив одним значением
\param[in/out] array[MAX_SIZE] Массив для заполнения
\param[in] countStrings  Кол-во элементов в массиве 
\param[in] value Значение, которым заполняется массив
*/
void fillArrayWithOneValue(int array[MAX_SIZE], int countStrings, int value);



/*!
Облегчение ребра графа
\param[in] i Город, откуда начинается дорога
\param[in] j Город, где дорога заканчивается
\param[in] ways[MAX_SIZE][MAX_SIZE] Матрица смежности
\param[in/out] minAmountOfWay[MAX_SIZE] Массив минимальных стоимостей маршрутов до каждого города
*/
void RelaxationOfGraphEdge(int i, int j, int ways[MAX_SIZE][MAX_SIZE], int minAmountOfWay[MAX_SIZE]);




/*!
Алгоритм Дейкстры
\param[in] countStrings Кол-во городов
\param[in] ways[MAX_SIZE][MAX_SIZE] Матрица смежности
\param[in/out] isWayUsed[MAX_SIZE] Массив использованных дорог
\param[in/out] minAmountOfWay[MAX_SIZE] Массив минимальных стоимостей маршрутов до каждого города
*/
void DijkstrasAlgorithm(int countStrings, int ways[MAX_SIZE][MAX_SIZE], int isWayUsed[MAX_SIZE], int minAmountOfWay[MAX_SIZE]);




/*!
Считать данные с .csv файла в строку
\param[in/out] data[] Указатель на файл для записи результата
\param[in] minAmountOfWay[MAX_SIZE] Массив минимальных стоимостей маршрутов до каждого города
\param[in] num_cities Кол-во городов
\return 0 или 1 в зависимости от результата работы функции (0 - функция отработала успешно, 1 - поймана ошибка)
*/
int writeResultToTxt(char* data[], int minAmountOfWay[MAX_SIZE], int num_cities);