#include<bits/stdc++.h>
using namespace std;

int solve(int i , int j , vector<vector<int>>& dp, vector<int> arr) {
	if(i == j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int mini = INT_MAX;
	for(int k = i; k < j; k++) {
		int op = arr[i - 1] * arr[k] * arr[j] + solve(i, k, dp, arr) + solve(k + 1, j, dp, arr);
		mini = min(mini, op);
	}
	return dp[i][j] = mini;
}


int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	vector<vector<int>> dp(n + 1 , vector<int>(n + 1, -1));
	int res = solve(1, n - 1, dp, arr);
	cout << res << endl;
    return 0;
}
