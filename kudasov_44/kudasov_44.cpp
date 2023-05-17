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



void RelaxationOfGraphEdge(int i, int j, int ways[MAX_SIZE][MAX_SIZE], int minAmountOfWay[MAX_SIZE]) {
    if (minAmountOfWay[i] + ways[i][j] < minAmountOfWay[j]) {
        minAmountOfWay[j] = minAmountOfWay[i] + ways[i][j];
    }
}

void DijkstrasAlgorithm(int countStrings, int ways[MAX_SIZE][MAX_SIZE], int isWayUsed[MAX_SIZE], int minAmountOfWay[MAX_SIZE]){

    minAmountOfWay[1] = 0;

    for (int i = 1; i < countStrings; i++) {
        int minAmount = infinity, w = -1;
        for (int j = 1; j <= countStrings; j++) {
            if (isWayUsed[j] == 0 && minAmountOfWay[j] < minAmount) {
                minAmount = minAmountOfWay[j];
                w = j;
            }
        }

        if (w < 0) {
            printf("Минимального пути из 1 в n-ый город не существует");
            break;
        }

        isWayUsed[w] = 1;

        for (int j = 1; j <= countStrings; j++) {
            if (isWayUsed[j] == 0 && ways[w][j] != infinity) {
                RelaxationOfGraphEdge(w, j, ways, minAmountOfWay);
            }
        }
    }
}

int readDataFromCsv(char* data[], char readDataMassive[1024], size_t sizeDataMassive)
{
    
    printf("%d", sizeDataMassive);
   FILE* infile = fopen(data[0], "r");

    if (infile == NULL) {
        printf("Error opening file121212.%s\n", data[0]);
        return 1;
    }

    
    size_t num_chars_read = 0;
    char* pos = readDataMassive;

    while (fgets(pos, sizeDataMassive - num_chars_read, infile)) {
        
        size_t len = strlen(pos);
        num_chars_read += len;
        pos += len;

        
        if (num_chars_read == sizeDataMassive - 1) {
            break;
        }
    }

   
    readDataMassive[num_chars_read] = '\0';
    printf("%s\n", readDataMassive);

    fclose(infile);
   
    return 0;
    
}

int writeResultToTxt(char* data[], int minAmountOfWay[MAX_SIZE], int num_cities)
    {
        FILE* outfile;
        if (minAmountOfWay[num_cities] == infinity) {
        printf("Минимального пути из 1 в n-ый город не существует\n");
        }
        else {

        outfile = fopen(data[0], "w");
        if (outfile == NULL) { 
            printf("Не удалось открыть файл.%s\n", data[0]);
            return 1;
        }

        fprintf(outfile, "%d", minAmountOfWay[num_cities]);
        fclose(outfile);
         }
        return 0;
}

int roads[MAX_SIZE][MAX_SIZE], isRoadUsed[MAX_SIZE], minAmountOfRoad[MAX_SIZE];

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    char inputDataStr[1024];
    size_t sizeInputMassive = sizeof(inputDataStr);
    int count_cities=0;


   
    if (argc < 3) { 
        printf("Необходимо передать имена входного и выходного файлов в качестве аргументов\n");
        return 1;
    }

    int result_input = readDataFromCsv(&argv[1], inputDataStr, sizeInputMassive);
    printf("%s\n", inputDataStr);
    
  

    sscanf(inputDataStr, "%d", &count_cities);
    printf("%d", count_cities);

    int sqr_count_cities = count_cities * count_cities;

    for (int i = 1; i <= count_cities; i++) {
        fillArrayWithOneValue(roads[i], count_cities, infinity);
    }

    int count_edges = 0;
    char* pos = inputDataStr;
    pos = strchr(pos, '\n');
   

    while (count_edges < sqr_count_cities) {
        int source=0, target=0, weight=0;
        if (sscanf(pos, "%d;%d;%d", &source, &target, &weight) != 3) {
            break;
        }

        printf("%d,%d,%d\n", source, target, weight);
        if (roads[source][target] == infinity) {
            roads[source][target] = weight;
            count_edges++;
        }
        pos = strchr(pos, '\n');
        
        if (pos == NULL) {
            break;
        }
        pos++;  // Пропускаем символ '\n'.
    }
    
    
    fillArrayWithOneValue(isRoadUsed, count_cities, 0);

    fillArrayWithOneValue(minAmountOfRoad, count_cities, infinity);

    DijkstrasAlgorithm(count_cities, roads, isRoadUsed, minAmountOfRoad);

    int result_output = writeResultToTxt(&argv[2], minAmountOfRoad, count_cities);
    
    return 0;
    
}

