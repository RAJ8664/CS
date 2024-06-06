#include<bits/stdc++.h>
using namespace std;

bool dfs(int u , int col, vector<vector<int>>& adj, vector<int>& color) {
	color[u] = col;
	for(int v : adj[u]) {
		if(color[v] == -1) {
			if(dfs(v, 1 - col, adj, color) == false) return false;
		}
		else if(color[v] == col) return false;
	}
	return true;
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


	vector<int> color(n + 1, -1);
	for(int i = 1; i <= n; i++) {
		if(color[i] == -1) {
			if(dfs(i, 1, adj, color) == false) {
				cout << "NO" << endl;
				return 0;
			}
		}

	}
	cout << "YES" << endl;
	return 0;
}
