#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[high];
    arr[high] = temp;

    int i = low - 1;
    
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        } else if (pivotIndex < k - 1) {
            return quickSelect(arr, pivotIndex + 1, high, k);
        } else {
            return quickSelect(arr, low, pivotIndex - 1, k);
        }
    }

    return -1; 
}

int main() {
    srand(time(0));

    int n = 50;
    int arr[n];
    for(int i = 0; i < n; i++) {
        int x = random() % 100;
        arr[i] = x;
    }

    for(int i = 0; i < n; i++) printf("%d " , arr[i]);
    int k = 5;

    int result = quickSelect(arr, 0, n - 1, k);
    if (result != -1) {
        printf("The %dth smallest element is: %d\n", k, result);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
