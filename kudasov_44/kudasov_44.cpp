// kudasov_44.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#pragma warning(disable : 4996)
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include "Header.h"


/**
*\file
*\brief Файл содержит вызываемые функции программы, а также управляющую функцию.
*\mainpage Документация для программы "TheShortestWayFromCity1ToCityN"
Программа должна определять стоимость самого дешевого путь из 1-ого города в N-ый, а также сам этот путь.

Для функционирования программы необходима операционная система Windows 10 или выше.
Программа будет разработана на языке С с применением библиотек <iostream>, <stdio.h>, <locale.h>. Дополнительного программного обеспечения не требуется.
Входные файлы могут быть подготовлены в редакторе Блокнот. Необходимо cохранять входные файлы в формате ".csv". Выходные файлы могут быть прочитаны с его помощью.

Исходный код программы является кроссплатформенным.
Программа должна получать два параметра командной строки: имя входного файла с данными о количестве городов и дорог между ними, а также стоимостью бензина в каждом из городов и имя файла
для записи стоимости самого дешевого пути из 1-ого города в N-ый, а также самого этотого пути.

Пример команды запуска программы:
*\code
kudasov_44.exe E:\2course\2cem\KiNPO\rep\input2.csv E:\2course\2cem\KiNPO\rep\output2.txt
*\endcode
*\author Кудасов Юрий Владиславович
*\date Май 2023 года
*\version 1.0
*/

int readDataFromCsv(char* data[], char readDataMassive[1024], size_t sizeDataMassive)
{
    /* Проверяем, что переданный указатель на массив параметров не равен NULL */
    if (data == NULL) {
        printf("Недопустимый файл с входными параметрами\n");
        return 1;
    }

    /* Проверяем, что переданный указатель на массив для считывания данных не равен NULL и что первый символ массива равен нулю */
    if (readDataMassive == NULL || readDataMassive[0]!=0) {
        printf("Недопустимый массив для считывания данных\n");
        return 1;
    }

    /* Получаем длину первого параметра */
    int lenn = strlen(data[0]);

    /* Проверяем, что размер массива для считывания данных больше или равен длине первого параметра */
    if (sizeDataMassive == 0 || lenn > sizeDataMassive) {
        printf("Недопустимый размер массива для считывания входных данных\n");
        return 1;
    }
    
    /* Открываем файл со входными данными для чтения */
    FILE* infile = fopen(data[0], "r");

    /* Проверяем, что файл был успешно открыт */
    if (infile == NULL) {
        printf("Ошибка открытия файла со входными данными %s\n", data[0]);
        return 1;
    }

    /* Инициализируем переменную для отслеживания количества считанных символов */
    size_t num_chars_read = 0;

    /* Устанавливаем указатель на начало массива для считывания данных */
    char* pos = readDataMassive;

    /* Читаем файл построчно и добавляем прочитанные данные в массив для считывания данных */
    while (fgets(pos, sizeDataMassive - num_chars_read, infile)) {

        /* Получаем длину строки, которую мы только что прочитали и устанавливаем указатель pos на конец прочитанной строки */
        size_t len = strlen(pos);
        num_chars_read += len;
        pos += len;

        /* Если мы считали все данные, которые могут поместиться в массив для считывания данных, выходим из цикла */
        if (num_chars_read == sizeDataMassive - 1) {
            break;
        }
    }

    /* Если мы не считали никаких данных и достигли конца файла, выводим сообщение об ошибке и закрываем файл */
    if (num_chars_read == 0 && feof(infile)) {
        printf("Файл с входными параметрами пуст\n");
        fclose(infile);
        return 1;
    }

    /* Добавляем нулевой символ в конец массива для считывания данных */
    if (num_chars_read < sizeDataMassive - 1) {
        readDataMassive[num_chars_read] = '\0';
    }
    else {
        readDataMassive[sizeDataMassive - 1] = '\0';
    }

    /* Закрываем файл */
    fclose(infile);

    /* Возвращаем 0, если функция была выполнена успешно */
    return 0;

}

void fillArrayWithOneValue(int array[MAX_SIZE], int countStrings, int value){
    
    /* Проверяем, что значение countStrings находится в допустимом диапазоне */
    if (countStrings < 1 || countStrings >= MAX_SIZE) {
        printf("Ошибка: некорректное значение countStrings\n");
        return;
    }

    /* Проверяем, что массив не является NULL */
    if (array == NULL) {
        printf("Ошибка: массив не может быть равен NULL\n");
        return;
    }

    /* Заполняем массив заданным значением */
    for (int z = 1; z <= countStrings; z++) {
        array[z] = value;
    }
}



void RelaxationOfGraphEdge(int i, int j, int ways[MAX_SIZE][MAX_SIZE], int minAmountOfWay[MAX_SIZE], int shortestPath[MAX_SIZE]) {
    
    /* Проверка корректности входных данных - индексов i и j */
    if (i < 1 || i >= MAX_SIZE || j < 1 || j >= MAX_SIZE || i==j) {
        printf("Некорректно заданы индексы городов для релаксации ребра\n");
        return;
    }

    /* Проверка корректности минимальных затрат на пути до города i */
    if (minAmountOfWay[i] == infinity || (minAmountOfWay[i] < 1 && i>1)) {
        printf("Некорректно задан массив минимальных затрат для города %d\n", i);
        return;
    }

    /* Проверка корректности стоимости дороги между городами i и j */
    if (ways[i][j] == infinity || ways[i][j] < 1) {
        printf("Стоимость дороги из города %d в город %d имеет некорректное значение\n", i, j);
        return;
    }

   /* Релаксация ребра между городами i и j */
    if (minAmountOfWay[i] + ways[i][j] < minAmountOfWay[j]) {
        minAmountOfWay[j] = minAmountOfWay[i] + ways[i][j];
        shortestPath[j] = i;
    }
}

void DijkstrasAlgorithm(int countStrings, int ways[MAX_SIZE][MAX_SIZE], int isWayUsed[MAX_SIZE], int minAmountOfWay[MAX_SIZE], int shortestPath[MAX_SIZE]){

    /* Проверяем, что количество городов задано корректно */
    if (countStrings > MAX_SIZE || countStrings<2) {
        printf("Ошибка: количество городов имеет некорректное значение");
        return;
    }

    /* Проверяем, что все входные массивы не являются нулевыми указателями */
    if (!ways || !isWayUsed || !minAmountOfWay || !shortestPath) {
        printf("Ошибка: один или несколько входных массивов являются нулевыми указателями");
        return;
    }

    /* Инициализируем массив минимальных затрат для первого города */
    minAmountOfWay[1] = 0;

    /* Находим кратчайший путь до оставшихся городов */
    for (int i = 1; i < countStrings; i++) {
        int minAmount = infinity, w = -1;
        /* Ищем вершину с наименьшим значением минимального пути */
        for (int j = 1; j <= countStrings; j++) {
            if (isWayUsed[j] == 0 && minAmountOfWay[j] < minAmount) {
                minAmount = minAmountOfWay[j];
                w = j;
            }
        }

        /* Если все оставшиеся города уже были посещены, выходим из цикла */
        if (w < 0) {
            break;
        }

        /* Помечаем вершину как посещенную */
        isWayUsed[w] = 1;

        /* Обновляем минимальные затраты для оставшихся городов */
        for (int j = 1; j <= countStrings; j++) {
            if (isWayUsed[j] == 0 && ways[w][j] != infinity) {
                RelaxationOfGraphEdge(w, j, ways, minAmountOfWay, shortestPath);
            }
        }
    }
}



int writeResultToTxt(char* data[], int minAmountOfWay[MAX_SIZE], int num_cities, int shortestPath[MAX_SIZE])
{
    FILE* outfile;

    /* Если не существует пути из первого города в n-ый город, выводим сообщение об ошибке */
    if (minAmountOfWay[num_cities] == infinity) {
        printf("Минимального пути из 1 в n-ый город не существует\n");
        return 1;
    }
    else {
        /* Открываем файл для записи */
        outfile = fopen(data[0], "w");

        /* Если не удалось открыть файл, выводим сообщение об ошибке и завершаем функцию */
        if (outfile == NULL) {
            printf("Не удалось открыть файл.%s\n", data[0]);
            return 1;
        }

        /* Записываем минимальное расстояние в файл */
        fprintf(outfile, "%d\n", minAmountOfWay[num_cities]);

        /* Выводим кратчайший путь из города 1 в город n */
        int path[MAX_SIZE], pathLength = 0;
        int v = num_cities;
        while (v != 1) {
            path[pathLength++] = v;
            v = shortestPath[v];
        }
        path[pathLength++] = 1;

        fprintf(outfile, "Кратчайший путь из города 1 в город %d: ", num_cities);
        for (int i = pathLength - 1; i >= 0; i--) {
            fprintf(outfile, "%d ", path[i]);
        }

        /* Закрываем файл */
        fclose(outfile);
    }

    /* Возвращаем 0, если функция была выполнена успешно */
     return 0;
}



int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    /* Три массива для хранения данных о дорогах, использованных дорогах и минимальном расстоянии от начальной вершины до остальных вершин соответственно */
    int roads[MAX_SIZE][MAX_SIZE], isRoadUsed[MAX_SIZE], minAmountOfRoad[MAX_SIZE];

    /* Строка для считывания данных с входного файла */
    char inputDataStr[1024]={ 0 };

    /* Определяем размер массива inputDataStr в байтах. */
    size_t sizeInputMassive = sizeof(inputDataStr);

    /* Инициализируем переменную count_cities, которая будет хранить количество городов. */
    int count_cities=0;

    /*  Массив для хранения предыдущих вершин на пути */
    int shortestWay[MAX_SIZE] = { 0 }; 
   
    /* Проверяем, что переданы имена входного и выходного файлов */
    if (argc < 3) { 
        
        printf("Необходимо передать имена входного или выходного файлов в качестве аргументов\n");
        return 1;
    }

    /* Считываем данные из входного файла в строку inputDataStr. */
    int result_input = readDataFromCsv(&argv[1], inputDataStr, sizeInputMassive);
    
    if (result_input == 1){
        return 1;
    }

    /* Считываем количество городов из строки с данными. */
    int num_scanned = sscanf(inputDataStr, "%d;;", &count_cities);

    /* Проверяем, что количество городов прочитано корректно. */
    if (num_scanned == 0 || count_cities < 2) {
        printf("Не удалось прочитать количество городов\n");
        return 1; // возвращаем код ошибки
    }
    /* Находим максимальное количество ребер в графе */
    int max_num_edges = count_cities * (count_cities-1);

    /* Инициализируем массив roads бесконечными значениями. */
    for (int i = 1; i <= count_cities; i++) {
        fillArrayWithOneValue(roads[i], count_cities, infinity);
    }

    /* Считываем данные о дорогах из строки с данными. */
    int count_edges = 0;
    char* pos = inputDataStr;
    pos = strchr(pos, '\n');
    pos++;

    while (count_edges < max_num_edges) {
        int source=0, target=0, weight=0;
        if (sscanf(pos, "%d;%d;%d", &source, &target, &weight) != 3) {
            if (sscanf(pos, "%d;%d;%d", &source, &target, &weight) > 0 && sscanf(pos, "%d;%d;%d", &source, &target, &weight) < 3)
            {
                printf("Один или несколько параметров имеют некорректные значения в строке %d\n", count_edges + 2);
                return 1; 
            }
            break;
        }

        
        /* Проверяем корректность данных о дорогах. */
        if (weight<1) {
            printf("Стоимость бензина имеет недопустимо малое значение %d в строке %d\n", weight, count_edges+2);
            return 1; // возвращаем код ошибки
        }

        if (source < 0 || source > count_cities || target < 0 || target > count_cities) {
            printf("Индекс начального %d или конечного города %d имеют неодопустимые значения в строке %d\n",source, target, count_edges + 2);
            return 1; // возвращаем код ошибки
        }

        if (source==target) {
            printf("Индекс начального %d или конечного города %d совпадают в строке %d\n", source, target, count_edges + 2);
            return 1; // возвращаем код ошибки
        }

        if (roads[source][target] != infinity) {
            printf("Из города %d в город %d больше одной дороги в строке %d\n", source, target, count_edges + 2);
            return 1; // возвращаем код ошибки
        }

            roads[source][target] = weight;
            count_edges++;
        
        pos = strchr(pos, '\n');
        /* Проверка на конец строки */
        if (pos == NULL) {
            break;
        }
        pos++;  
    }
    
   /* Заполняем массивы isRoadUsed и minAmountOfRoad значениями 0 и infinity соответственно */
    fillArrayWithOneValue(isRoadUsed, count_cities, 0);

    fillArrayWithOneValue(minAmountOfRoad, count_cities, infinity);

    /* Запускаем алгоритм Дейкстры для нахождения кратчайших путей от начальной вершины до всех остальных вершин */
    DijkstrasAlgorithm(count_cities, roads, isRoadUsed, minAmountOfRoad, shortestWay);

    /* Записываем результаты в файл, используя функцию writeResultToTxt, и сохраняем результат в переменной result_output */
    int result_output = writeResultToTxt(&argv[2], minAmountOfRoad, count_cities, shortestWay);

    /* Если произошла ошибка при записи в файл, то программа возвращает код ошибки 1 */
    if (result_output == 1) {
        return 1;
    }
    /* Если запись в файл прошла успешно, то программа возвращает код успешного завершения 0 */
    return 0;
    
}

