// kudasov_44.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#pragma warning(disable : 4996)
#include <iostream>
#include <locale.h>
#include <stdio.h>


const int infinity = 100000;

void fillArrayWithOneValue(int array[100], int countStrings, int value){
    for (int z = 1; z <= countStrings; z++) {
        array[z] = value;
    }
}

int roads[100][100], isRoadUsed[100], minAmountOfRoad[100], costOfRoad[100];

void RelaxationOfGraphEdge(int i, int j) {
    if (minAmountOfRoad[i] + roads[i][j] < minAmountOfRoad[j]) {
        minAmountOfRoad[j] = minAmountOfRoad[i] + roads[i][j];
    }
}

void DijkstrasAlgorithm(int countStrings){

    minAmountOfRoad[1] = 0;

    for (int i = 1; i < countStrings; i++) {
        int minAmount = infinity, w = -1;
        for (int j = 1; j <= countStrings; j++) {
            if (isRoadUsed[j] == 0 && minAmountOfRoad[j] < minAmount) {
                minAmount = minAmountOfRoad[j];
                w = j;
            }
        }

        if (w < 0) {
            printf("Минимального пути из 1 в n-ый город не существует");
            break;
        }

        isRoadUsed[w] = 1;

        for (int j = 1; j <= countStrings; j++) {
            if (isRoadUsed[j] == 0 && roads[w][j] != infinity) {
                RelaxationOfGraphEdge(w, j);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    FILE* infile;
    FILE* outfile;
    int num_cities;
    int num_edges = 0;
   
    if (argc < 3) { // Проверяем, переданы ли аргументы
        printf("Необходимо передать имена входного и выходного файлов в качестве аргументов\n");
        return 1;
    }

    infile = fopen(argv[1], "r");

    if (infile==NULL) {
        printf("Error opening file121212.%s\n", argv[1]);
        return 1;
    }

    printf("Введите кол-во городов: ");
    fscanf(infile, "%d", &num_cities);
    int sqr_num_cities = num_cities * num_cities;

    for (int i = 1; i <= num_cities; i++) {
        fillArrayWithOneValue(roads[i], num_cities, infinity);
    }

    while (num_edges < sqr_num_cities) {
        int source, target, weight;
        if (fscanf(infile, "%d,%d,%d", &source, &target, &weight) != 3) {
            break;
        }
        roads[source][target] = weight;
        num_edges++;
    }


    fclose(infile);
    
    fillArrayWithOneValue(isRoadUsed, num_cities, 0);

    fillArrayWithOneValue(minAmountOfRoad, num_cities, infinity);

    DijkstrasAlgorithm(num_cities);

    if (minAmountOfRoad[num_cities] == infinity) {
        printf("Минимального пути из 1 в n-ый город не существует\n");
    }
    else {

        outfile = fopen(argv[2], "w"); // открыть файл для записи
        if (outfile == NULL) { // проверить, открылся ли файл
            printf("Не удалось открыть файл.%s\n", argv[2]);
            return 1;
        }

        fprintf(outfile, "%d", minAmountOfRoad[num_cities]);
        fclose(outfile);
    }

    return 0;
}

