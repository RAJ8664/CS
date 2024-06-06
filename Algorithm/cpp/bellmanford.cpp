#include<bits/stdc++.h>
using namespace std;

int bellmanford(int src, int dest, vector<vector<pair<int, int>>>& adj, int n) {
	vector<int> dist(n + 1, (int)(1e9));
	dist[src] = 0;
	for(int i = 1; i <= n; i++) {
		for(auto& it : adj[i]) {
			int parent_node = i;
			int child_node = it.second;
			int child_dist = it.first;
			if(dist[i] != (int)(1e9) && dist[child_node] > child_dist + dist[i]) {
				dist[child_node] = dist[i] + child_dist;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(auto& it : adj[i]) {
			int parent = i;
			int child_node = it.second;
			int child_dist = it.first;
			if(dist[parent] != (int)(1e9) && dist[parent] + child_dist < dist[child_node]) {
				cout << "NEGATIVE CYCLE DETECTED!";
				return -1;
			}
		}
	}

	return dist[dest];
}

int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < m; i++) {
		int u , v, dist;
		cin >> u >> v >> dist;
		adj[u].push_back(make_pair(dist, v));
	}

	int src, dest;
	cin >> src >> dest;
	int res = bellmanford(src, dest, adj, n);
	cout << res << endl;
    return 0;
}
