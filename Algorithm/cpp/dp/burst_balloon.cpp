#include<bits/stdc++.h>
using namespace std;

int solve(int i , int j ,vector<vector<int>>& dp, vector<int> arr) {
	if(i > j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int maxi = INT_MIN;
	for(int k = i; k <= j; k++) {
		int op = arr[i - 1] * arr[k] * arr[j + 1] + solve(i , k - 1, dp, arr) + solve(k + 1, j, dp, arr);
		maxi = max(maxi, op); 
	}
	return dp[i][j] = maxi;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	arr.insert(arr.begin(), 1);
	arr.push_back(1);
	vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));
	int res = solve(1, arr.size() - 2, dp, arr);
	cout << res << endl;
	return 0;
}
