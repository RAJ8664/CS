#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	vector<int> temp;
	while(i <= mid && j <= high) {
		if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
		else temp.push_back(arr[j++]);
	}
	while(i <= mid) temp.push_back(arr[i++]);
	while(j <= high) temp.push_back(arr[j++]);
	int cnt = 0;
	for(int k = low; k <= high; k++) {
		arr[k] = temp[cnt++];
	}
}

void merge_sort(vector<int>& arr, int low, int high) {
	if(low < high) {
		int mid = low + (high - low) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	merge_sort(arr, 0 , n - 1);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
        return 0;
}
