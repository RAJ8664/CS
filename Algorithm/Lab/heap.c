/*Author : RAJ ROY*/

#include<stdio.h>
#include<stdlib.h>

int last;
void heapify(int n , int arr[] , int heap[]) {
	for(int i = 1; i <= n; i++) heap[i] = arr[i];
	for(int i = n; i >= 1; i++) {
		int left = i * 2;
		int right =i * 2 + 1;
		if(left < n && right < n) {
			int le = heap[i * 2];
			int re = heap[i * 2 + 1];
			int lm = -1;
			int rm = -1;
			if(lm > rm) lm = 0;
			else rm = 0;
			if(lm == 0) {
				int start = i;
				if(lm > heap[i]) {

				}
			}
			else if(rm == 0) {

			}
			else break;
		}
		else if(left < n && right >= n) {

		}
		else if(right < n && left >= n) {

		}
	}
}

void make_heap(int n , int arr[] , int heap[]) {
	for(int i = 1; i <= n; i++) {
		int insert_ele = arr[i];
		if(i == 1) {
			heap[i] = insert_ele;
		}
		else {
			heap[i] = insert_ele;
			int start = i;
			while(start > 1 && heap[start] > heap[start / 2]) {
				int temp = heap[start];
				heap[start] = heap[start / 2];
				heap[start / 2] = temp;
				start = start / 2;
			}
		}
	}
}


void del(int n, int arr[]) {
	for(int i = 1; i <= n; i++) {
		int current_max = arr[1];
		arr[1] = arr[last];
		arr[last] = current_max;
		int start = 1;
		while(start * 2 < last && start * 2 + 1 < last) {
			int left = arr[start * 2];
			int right = arr[start * 2 + 1];
			int lm = -1;
			int rm = -1;
			if(left > right) {
				lm = 0;
			}
			else rm = 0;
			if(lm == 0) {
				if(left > arr[start]) {
					int temp = arr[start * 2];
					arr[start * 2] = arr[start];
					arr[start] = temp;
					start = start * 2;
				}
				else break;
			}
			else if(rm == 0) {
				if(right > arr[start]) {
					int temp = arr[2 * start + 1];
					arr[2 * start + 1] = arr[start];
					arr[start] = temp;
					start = start * 2 + 1;
				}
				else break;
			}
		}
		last--;
	}
}


int main() {
	int n;
	scanf("%d", &n);
	int arr[n + 1];
	for(int i = 1; i <= n; i++) {
		int x;scanf("%d", &x);
		arr[i] = x;
	}

	int heap[n + 1];
	for(int i = 0; i <= n; i++) heap[i] = -1;
	make_heap(n , arr, heap);
	last = n;
	del(n , heap);
	for(int i = 1; i <= n; i++) {
		printf("%d " , heap[i]);
	}
	return 0;
}
