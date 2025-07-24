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

int findMax(float arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
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

    int minTempIndex = findMin(temp, n);
    int maxTempIndex = findMax(temp, n);
    printf("Minimum temperature (Linear Search): %.2f\n", temp[minTempIndex]);
    printf("Maximum temperature (Linear Search): %.2f\n", temp[maxTempIndex]);

    int minPressureIndex = findMin(pressure, n);
    int maxPressureIndex = findMax(pressure, n);
    printf("Minimum pressure (Linear Search): %.2f\n", pressure[minPressureIndex]);
    printf("Maximum pressure (Linear Search): %.2f\n", pressure[maxPressureIndex]);

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
    printf("Time required for temperature = %lf seconds\n", duration);

    start = clock();
    int minIndxPressure = findMin(arr_pressure, largeN);
    end = clock();
    duration = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time required for pressure = %lf seconds\n", duration);

    return 0;
}
