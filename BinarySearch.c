#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateData(float arr[], int n, float low, float high) {
    for (int i = 0; i < n; i++) {
        arr[i] = low + ((float)rand() / RAND_MAX) * (high - low);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float sorted_temp[n];
    for (i = 0; i < n; i++) {
        sorted_temp[i] = 20 + ((float)i / (n - 1)) * (50 - 20);
    }

    printf("SORTED TEMPERATURE: ");
    for (i = 0; i < n; i++)
        printf("%.2f, ", sorted_temp[i]);
    printf("\n");

    int index_linear = -1;
    clock_t start = clock();
    for (i = 0; i < n; i++) {
        if (sorted_temp[i] >= 30.0) {
            index_linear = i;
            break;
        }
    }
    clock_t end = clock();
    double duration_linear = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (index_linear != -1)
        printf("First temperature >= 30 using Linear Search: %.2f at index %d\n",
               sorted_temp[index_linear], index_linear);

    printf("Linear Search time = %lf seconds\n", duration_linear);

    int low = 0, high = n - 1, result = -1;
    start = clock();
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sorted_temp[mid] >= 30.0) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    end = clock();
    double duration_binary = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search time = %lf seconds\n", duration_binary);

    return 0;
}
