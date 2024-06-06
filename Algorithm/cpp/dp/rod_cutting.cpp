#include<bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> cost, int curr_length , vector<vector<int>>& dp) {
	if(ind == 0) return curr_length * cost[0];
	if(dp[ind][curr_length] != -1) return dp[ind][curr_length];
	int not_take = solve(ind - 1, cost, curr_length, dp);
	int take = INT_MIN;
	if(curr_length >= ind + 1) {
		take = cost[ind] + solve(ind, cost, curr_length - (ind + 1) , dp);
	}
	return dp[ind][curr_length] = max(take , not_take);
}


int main() {
	int n;
	cin >> n;
	vector<int> cost(n);
	for(int i = 0; i < n; i++) cin >> cost[i];
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); 
	int res = solve(n - 1, cost, n , dp);
	cout << res << endl;
	return 0;
}
