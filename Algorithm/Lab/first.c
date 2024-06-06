#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int main() {
	srand(time(0));
	int n = 30000;
	int arr[n];
	for(int i = 0; i < n; i++) {
		int x = rand() % 100000;
		arr[i] = x;
	}

	int first_smallest = INT_MAX;
	int second_smallest = INT_MAX;

	int total_comparison = 0;

	for(int i = 0; i < n; i++) {
		int current = arr[i];
		total_comparison++;
		if(first_smallest > current) {
			first_smallest = current;
			
		}
	}
	for(int i = 0; i < n; i++) {
		int current = arr[i];
		total_comparison++;
		if(second_smallest > current && current != first_smallest) {
			second_smallest = current;	
		}
	}

	printf("First Smallest = %d\n" , first_smallest);
	printf("Second Smallest = %d\n" , second_smallest);
	printf("Total Comparison = %d\n" , total_comparison);
	return 0;
}
