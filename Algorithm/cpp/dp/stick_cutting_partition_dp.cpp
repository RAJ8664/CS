#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& cuts, int length) {
	int n = cuts.size();
	vector<vector<int>> dp(n + 3, vector<int>(n + 3, 0));
	cuts.push_back(0);
	cuts.push_back(length);
	sort(cuts.begin(), cuts.end());
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= n; j++) {
			int mini = INT_MAX;
			if(i > j) continue;
			for(int k = i; k <= j; k++) {
				int op = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
				mini = min(mini, op);
			}
			dp[i][j] = mini;
		}
	}
	return dp[1][n];
}


int main() {
	int n;
	cin >> n;
	vector<int> cuts(n);
	for(int i = 0; i < n; i++) cin >> cuts[i];
	int length;
	cin >> length;
	int res = solve(cuts, length);
	cout << res << endl;
	return 0;
}
