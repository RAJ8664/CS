#include<bits/stdc++.h>
using namespace std;

int solve(int i , int j , vector<vector<int>>& dp, string s, string t) {
	if(i < 0 || j < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(s[i] == t[j]) {
		return dp[i][j] = 1 + solve(i - 1, j - 1, dp, s , t);
	}
	return dp[i][j] = max(solve(i - 1, j , dp, s, t) , solve(i , j - 1, dp , s, t));
}

int main() {
	string s, t;
    cin >> s >> t;
	int n = (int)s.size();
	int m = (int)t.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	int res = solve(n - 1, m - 1, dp, s, t);
	cout << res << endl;
	return 0;
}
