#include<bits/stdc++.h>
using namespace std;

int solve(int i , int j , vector<vector<int>>& dp, string s, string t) {
	if(i >= s.size() || j >= t.size()) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(s[i] == t[j]) return dp[i][j] = 1 + solve(i + 1, j + 1, dp, s, t);
	return dp[i][j] = max(solve(i + 1, j , dp, s, t) , solve(i , j + 1, dp, s, t));
}

int main() {
	string s, t;
        cin >> s >> t;
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	int res = solve(0 , 0 , dp, s, t);
	int a = 0;
	int b = 0;
	string ans = "";
	while(res > 0) {
		if(a < n && solve(a + 1, b , dp, s, t) == res) {
			a++;
			continue;
		}
		if(b < m && solve(a, b + 1, dp , s, t) == res) {
			b++;
			continue;
		}
		ans += s[a];
		a++;
		b++;
		res--;
	}
	cout << ans << endl;
    return 0;
}
