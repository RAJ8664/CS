#include<bits/stdc++.h>
using namespace std;

void dfs(int u , vector<int>& vis, vector<vector<int>>& adj , vector<int>& res) {
    res.push_back(u);
    vis[u] = 1;
    for(int v : adj[u]) {
        if(vis[v] == 0) dfs(v, vis, adj,res);
    }
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
    vector<int> res;
    int src; cin >> src;
    dfs(src, vis, adj, res);
    for(int ele : res) cout << ele << " ";
    cout << endl;
    return 0;
}
