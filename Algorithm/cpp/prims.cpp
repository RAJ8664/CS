#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> prims_edges;
int prim(vector<vector<pair<int, int>>>& adj, int n) {
	int sum = 0;
	vector<int> vis(n + 1, 0);
	vector<int> parent(n + 1, -1);
	priority_queue<pair<int , int> , vector<pair<int, int>> , greater<pair<int , int>>> pq;
	pq.push(make_pair(0 , 1));
	while(!pq.empty()) {
		auto it = pq.top();
		pq.pop();

		int curr_node = it.second;
		int curr_dist = it.first;

		if(vis[curr_node] == 1) continue;
		sum += curr_dist;

		if(parent[curr_node] != -1) {
			prims_edges.push_back(make_pair(parent[curr_node] , curr_node));
		}

		vis[curr_node] = 1;
		for(auto it : adj[curr_node]) {
			int child_node = it.second;
			int child_dist = it.first;
			if(vis[child_node] == 0) {
				pq.push(make_pair(child_dist, child_node));
				if (parent[child_node] == -1 || child_dist < adj[child_node][parent[child_node]].first) {
                    parent[child_node] = curr_node;
                }
			}
		}
	}
	return sum;
}


int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < m; i++) {
		int u , v , dist;
		cin >> u >> v >> dist;
		adj[u].push_back(make_pair(dist, v));
		adj[v].push_back(make_pair(dist, u));
	}

	int res = prim(adj, n);
	cout << res << endl;
	for(pair<int , int> curr: prims_edges) {
		cout << curr.first << " " << curr.second << endl;
	}
    return 0;
}
