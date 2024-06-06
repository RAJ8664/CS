
#include<bits/stdc++.h>
using namespace std;

int djikstra(int src, int dest, vector<vector<pair<int, int>>> adj, int n) {
    vector<int> dist(n + 1, (int)(1e9));
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while(!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        for(auto& it : adj[current_node]) {
            int child_node = it.second;
            int child_dist = it.first;
            if(dist[child_node] > child_dist + current_dist) {
                dist[child_node] = child_dist + current_dist;
                pq.push(make_pair(dist[child_node] , child_node));
            }
        }
    }
    if(dist[dest] == (int)(1e9)) return -1;
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
        adj[v].push_back(make_pair(dist, u));
    }

    int src, dest;
    cin >> src >> dest;
    int res = djikstra(src, dest, adj, n);
    cout << res << endl;
    return 0;
}
