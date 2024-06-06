#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		int j = i;
		while(j - 1 >= 0 && arr[j] < arr[j - 1]) {
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

int main() {
	srand(time(0));

	int n = 30000;
	printf("%d\n" , n);
	int arr[n];

	for(int i = 0; i < n; i++) {
		int r = rand();
		arr[i] = r;
	}

	insertion_sort(arr, n);
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
