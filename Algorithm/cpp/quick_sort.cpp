#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int getRandomPivot(int low, int high) {
    random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> distr(low, high); 
    return distr(gen);
}

int findMedian(int arr[], int low, int mid, int high) {
    if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low]))
        return mid;
    else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid]))
        return low;
    else
        return high;
}

int partition1(int arr[], int low, int high) 
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
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[low], arr[j]); 
    return j; 
} 


int partition2(int arr[], int low, int high) {
    int medianIndex = findMedian(arr, low, (low + high) / 2, high);
    swap(arr[medianIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void Quick_Sort(int arr[], int low, int high){
    if(low < high){
        int partitionIndex = partition1(arr, low, high);
        Quick_Sort(arr, low, partitionIndex - 1);
        Quick_Sort(arr, partitionIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	arr[i] = x;
    }
    Quick_Sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
