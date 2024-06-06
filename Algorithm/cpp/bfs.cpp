#include<bits/stdc++.h>
using namespace std;

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

    vector<int> res;
    vector<int> vis(n + 1, 0);
    int src; cin >> src;
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()) {
        int current = q.front();
        res.push_back(current);
        q.pop();
        for(int v : adj[current]) {
            if(vis[v] == 0) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    for(int ele : res) cout << ele << " ";
    cout << endl;
    return 0;
}
