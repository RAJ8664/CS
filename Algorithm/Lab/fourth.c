/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int getRandomPivot(int low, int high) {
    return low + rand() % (high - low + 1);
}

int findMedian(int arr[], int low, int mid, int high) {
    if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low]))
        return mid;
    else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid]))
        return low;
    else
        return high;
}


//This is standard quick sort selection first element as pivot index always;
int partition(int arr[], int low, int high) 
{ 
  
    int pivot = arr[low]; 
    int i = low; 
    int j = high; 
  
    while (i < j) { 
        while (arr[i] <= pivot && i <= high - 1) { 
            i++; 
        } 
        while (arr[j] > pivot && j >= low + 1) { 
            j--; 
        } 
        if (i < j) { 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[low], &arr[j]); 
    return j; 
} 


// selecting pivot index as random value in the range low to high;

int partition1(int arr[], int low, int high) {

    // Choose a random pivot and swap it with the last element
    int pivotIndex = getRandomPivot(low, high);
    swap(&arr[pivotIndex], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


//selecting median as the pivot element;
int partition2(int arr[], int low, int high) {
    
    int medianIndex = findMedian(arr, low, (low + high) / 2, high);
    swap(&arr[medianIndex], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void Quick_Sort(int arr[],int low,int high){
        if(low < high){
            int partitioner_index = partition2(arr,low,high);
            Quick_Sort(arr, low, partitioner_index - 1);
            Quick_Sort(arr, partitioner_index + 1, high);
        }
}

 
int main() {

	int n = 20;
	int arr[n];
	for(int i = 0; i < n; i++) {
		int x = rand() % 10000;
		arr[i] = x;
	} 

	Quick_Sort(arr, 0, n - 1);
	for(int i = 0; i < n; i++) printf("%d " , arr[i]);
	printf("\n");
	return 0;
}
