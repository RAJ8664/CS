#include<bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pv) {
	vis[u] = 1;
	pv[u] = 1;
	for(int v : adj[u]) {
		if(vis[v] == 0) {
			if(dfs(v, adj, vis, pv) == true) return true;
		}
		else if(pv[v] == 1) return true;
	}

	pv[u] = 0;
	return false;
}


int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> vis(n + 1, 0);
	vector<int> pv(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			if(dfs(i , adj, vis, pv) == true) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
