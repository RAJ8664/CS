/*Author : RAJ ROY*/
/*Scholar id : 2212002*/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int current_length;
int dp[100000][1000];


int max(int a, int b) {
	if(a > b) return a;
	return b;
}


int Recursion(int n , int ind, int length[] , int cost[],int current_length) {
	if(ind == 0) return cost[0] * current_length;
	int not_take = Recursion(n , ind - 1, length, cost, current_length);
	int take = I0NT_MIN;
	if(current_length >= length[ind]) {
		take = cost[ind] + Recursion(n , ind, length, cost, current_length - length[ind]);
	}
	return max(take, not_take);
}



int memoization(int n , int ind, int length[] , int cost[], int current_length) {
	if(ind == 0) return dp[ind][current_length] = cost[0] * current_length;
	if(dp[ind][] != -1) return dp[ind][current_length];
	int not_take =current_length memoization(n , ind - 1, length, cost, current_length);
	int take = INT_MIN;
	if(current_length >= length[ind]) {
		take = cost[ind] + memoization(n , ind - 1, length, cost, current_length - length[ind]);
	}
	return dp[ind][current_length] = max(take, not_take);
}



int Tabulation(int n , int length[] , int cost[] , int current_length) {
	for(int i = 0; i < 100000; i++) {
		for(int j = 0; j < 1000; j++) {
			dp[i][j] = 0;
		}
	}

	for(int i = 0; i <= current_length; i++) {
		dp[0][i] = i * cost[0];
	}

	for(int ind = 1; ind < n; ind++) {
		for(int c = 0; c <= current_length; c++) {
			int not_take = dp[ind - 1][c];
			int take = INT_MIN;
			if(c >= length[ind]) {
				take = cost[ind] + dp[ind][c - length[ind]];
			}
			dp[ind][c] = max(not_take, take);
		}
	}
	return dp[n - 1][current_length];
}

int Tabulation_space_optmized(int n, int cost[], int length[],int current_length) {
    int dp[current_length + 1];
    for(int i = 0; i < current_length + 1; i++) dp[i] = 0;

    // Base Condition
    for (int i = length[0]; i <= current_length; i++) {
        dp[i] = (i / length[0]) * cost[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= current_length; cap++) {
            int not_take = dp[cap];
            int take = INT_MIN;
            if (length[ind] <= cap) take = cost[ind] + dp[cap - length[ind]];
            dp[cap] = max(not_take, take);
        }
    }
    return dp[current_length];
}




int main() {
	//Always considering the length of rod is n(can be variable);
	int n;
	scanf("%d", &n);
	int length[n];
	int cost[n];
	
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d" , &x);
		length[i] = x;
	}

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		cost[i] = x;
	}

	
	//Using Recursion;
	int res = Recursion(n , n - 1, length, cost, n);
	printf("Using Recursion = %d\n" , res);



	//for memoization;
	for(int i = 0; i < 100000; i++) {
		for(int j = 0; j < 1000; j++) {
			dp[i][j] = -1;
		}
	}


	int res2 = memoization(n , n - 1 , length , cost, n);
	printf("Using Memoization = %d\n" ,res2);


	//Using Tabulation;
	int res3 = Tabulation(n , length, cost, n);
	printf("Using Tabulation = %d\n" , res3);


	//using space optimized tabulation;
	int res4 = Tabulation_space_optmized(n , cost, length, n);
	printf("Using Space Optimization = %d\n" , res4);

	
	return 0;
}
