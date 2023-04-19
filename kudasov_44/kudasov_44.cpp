// kudasov_44.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#pragma warning(disable : 4996)
#include <iostream>
#include <locale.h>



const int infinity = 100000;


int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m;
    int roads[100][100], isRoadUsed[100], minAmountOfRoad[100], costOfRoad[100];
    
    printf("Введите кол-во городов: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            roads[i][j] = infinity;
        }
    }

    printf("Введите стоимость бензина в каждом из городов: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &costOfRoad[i]);
    }

    printf("Введите кол-во дорог между городами: ");
    scanf("%d", &m);

    printf("Введите кол-во дорог между городами: ");
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        roads[a][b] = costOfRoad[a];
        roads[b][a] = costOfRoad[b];
    }

}

