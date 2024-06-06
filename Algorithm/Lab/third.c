/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>

int count = 0;
int maxi = INT_MIN;
int mini = INT_MAX;

void solve(int arr[], int n)
{ 
	int i; 
	if (n % 2 == 0)
	{	
		count += 1;	 
		if (arr[0] > arr[1])	 
		{
			maxi = arr[0];
			mini = arr[1];
			
		} 
		else


		{
			mini = arr[0];
			maxi = arr[1];
			
		}

		i = 2; 
	} 

	else
	{
		mini = arr[0];
		maxi = arr[0];
		i = 1;
	}

	
	while (i < n-1) 
	{
		count += 1;		 
		if (arr[i] > arr[i+1])		 
		{
			count += 2;

			if(arr[i] > maxi) {
				maxi = arr[i];	
			}
				
			if(arr[i+1] < mini){
				mini = arr[i + 1];
				
			}		 
					 
		} 
		else		
		{
			count += 2;
			if (arr[i+1] > maxi){
				maxi = arr[i + 1];
			} 
				
			if (arr[i] < mini) {
				mini = arr[i];
			}		 		 
		}	 

		i += 2; 
	}		 
} 


int main(){
	srand(time(0));
	int n = 30000;
	int arr[n];
	for(int i = 0; i < n; i++) {
		int x = rand() % 50;
		arr[i] = x;
	}

	printf("\n");

	solve(arr, n);
	printf("Minimum = %d and Maximum = %d\n" , mini , maxi);
	printf("Total Number of elements = %d\n", n);
	printf("Total comparison = %d\n " , count);
	return 0;
}

