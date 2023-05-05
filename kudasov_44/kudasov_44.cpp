// kudasov_44.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#pragma warning(disable : 4996)
#include <iostream>
#include <locale.h>
#include <stdio.h>
#define MAX_SIZE 100

const int infinity = 100000;

void fillArrayWithOneValue(int array[MAX_SIZE], int countStrings, int value){
    for (int z = 1; z <= countStrings; z++) {
        array[z] = value;
    }
}

int roads[MAX_SIZE][MAX_SIZE], isRoadUsed[MAX_SIZE], minAmountOfRoad[MAX_SIZE], costOfRoad[MAX_SIZE];

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

int readDateFromCsv(char* data[], int roads[MAX_SIZE][MAX_SIZE])
{
    int num_cities;
    int num_edges = 0;
   FILE* infile = fopen(data[0], "r");

    if (infile == NULL) {
        printf("Error opening file121212.%s\n", data[0]);
        return 1;
    }
    
    printf("Введите кол-во городов: ");
    fscanf(infile, "%d", &num_cities);

    int sqr_num_cities = num_cities * num_cities;
    
    for (int i = 1; i <= num_cities; i++) {
        fillArrayWithOneValue(roads[i], num_cities, infinity);
    }

    while (num_edges <= sqr_num_cities) {
        int source, target, weight;
        if (fscanf(infile, "%d;%d;%d", &source, &target, &weight) != 3) {
            break;
        }
        
        if (roads[source][target] == infinity) {
            roads[source][target] = weight;
            num_edges++;
            
        }
    }
    fclose(infile);
    return num_cities;
}

int writeResultToTxt(char* data[], int minAmountOfRoad[MAX_SIZE], int num_cities)
    {
        FILE* outfile;
        if (minAmountOfRoad[num_cities] == infinity) {
        printf("Минимального пути из 1 в n-ый город не существует\n");
        }
        else {

        outfile = fopen(data[0], "w");
        if (outfile == NULL) { 
            printf("Не удалось открыть файл.%s\n", data[0]);
            return 1;
        }

        fprintf(outfile, "%d", minAmountOfRoad[num_cities]);
        fclose(outfile);
         }
        return 0;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    
    
    int count_cities;
    
   
    if (argc < 3) { 
        printf("Необходимо передать имена входного и выходного файлов в качестве аргументов\n");
        return 1;
    }

    count_cities = readDateFromCsv(&argv[1], roads);
    
    fillArrayWithOneValue(isRoadUsed, count_cities, 0);

    fillArrayWithOneValue(minAmountOfRoad, count_cities, infinity);

    DijkstrasAlgorithm(count_cities);

    int result = writeResultToTxt(&argv[2], minAmountOfRoad, count_cities);
    
    return 0;
    
}

