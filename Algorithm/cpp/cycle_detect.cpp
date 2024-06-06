#include<bits/stdc++.h>
using namespace std;

bool dfs(int u , int par, vector<int>& vis, vector<vector<int>>& adj) {
	vis[u] = 1;
	bool ans = false;
	for(int v : adj[u]) {
		if(vis[v] == 1 && v == par) continue;
		else if(vis[v] == 1) return true;
		ans |= dfs(v, u, vis, adj);
	}
	return ans;
}

int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			if(dfs(i , -1, vis, adj) == true) {
				cout << "true" << endl;
				return 0;
			}
		}
	}
	cout << "false" << endl;
	return 0;
}
