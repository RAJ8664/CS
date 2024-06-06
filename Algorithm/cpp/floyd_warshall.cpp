#include<bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>>& adj, int n) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) adj[i][j] = 0;
		}
	}

	for(int via = 1; via <= n; via++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				adj[i][j] = min(adj[i][j] , adj[i][via] + adj[via][j]);
			}
		}
	}
}


int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, (int)(1e9)));
	for(int i = 0; i < m; i++) {
		int u , v , dist;
		cin >> u >> v >> dist;
		adj[u][v] = dist;
		
	}

	floyd_warshall(adj, n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(adj[i][j] == (int)(1e9)) {
				cout << -1 << " ";
			}
			else cout << adj[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}
