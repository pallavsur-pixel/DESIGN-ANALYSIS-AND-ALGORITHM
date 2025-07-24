#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateData(float arr[], int n, float low, float high) {
    for (int i = 0; i < n; i++) {
        arr[i] = low + ((float)rand() / RAND_MAX) * (high - low);
    }
}

int findMin(float arr[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }
    return minIndex;
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float temp[n], pressure[n];
    srand(time(0));

    for (i = 0; i < n; i++) {
        temp[i] = -20 + ((float)rand() / RAND_MAX) * (50 - (-20));
        pressure[i] = 950 + ((float)rand() / RAND_MAX) * (1050 - 950);
    }

    printf("TEMPERATURE: ");
    for (i = 0; i < n; i++)
        printf("%.2f, ", temp[i]);
    printf("\n");

    printf("PRESSURE: ");
    for (i = 0; i < n; i++)
        printf("%.2f, ", pressure[i]);
    printf("\n");

    float minValTemp = temp[0], maxValTemp = temp[0];
    for (i = 0; i < n; i++) {
        int isMin = 1, isMax = 1;
        for (int j = 0; j < n; j++) {
            if (temp[j] < temp[i])
                isMin = 0;
            if (temp[j] > temp[i])
                isMax = 0;
        }
        if (isMin)
            minValTemp = temp[i];
        if (isMax)
            maxValTemp = temp[i];
    }
    printf("Minimum temperature (Naive Pairwise): %.2f\n", minValTemp);
    printf("Maximum temperature (Naive Pairwise): %.2f\n", maxValTemp);

    float minValPres = pressure[0], maxValPres = pressure[0];
    for (i = 0; i < n; i++) {
        int isMin = 1, isMax = 1;
        for (int j = 0; j < n; j++) {
            if (pressure[j] < pressure[i])
                isMin = 0;
            if (pressure[j] > pressure[i])
                isMax = 0;
        }
        if (isMin)
            minValPres = pressure[i];
        if (isMax)
            maxValPres = pressure[i];
    }
    printf("Minimum pressure (Naive Pairwise): %.2f\n", minValPres);
    printf("Maximum pressure (Naive Pairwise): %.2f\n", maxValPres);

    int largeN = 1000000;
    float arr_temp[largeN];
    float arr_pressure[largeN];

    generateData(arr_temp, largeN, 20, 50);
    generateData(arr_pressure, largeN, 950, 1050);

    double duration;
    clock_t start, end;

    start = clock();
    int minIndxTemp = findMin(arr_temp, largeN);
    end = clock();
    duration = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for temperature = %lf seconds\n", duration);

    start = clock();
    int minIndxPressure = findMin(arr_pressure, largeN);
    end = clock();
    duration = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for pressure = %lf seconds\n", duration);

    return 0;
}
