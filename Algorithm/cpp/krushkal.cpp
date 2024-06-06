#include<bits/stdc++.h>
using namespace std;


class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int node) {
        if(node == parent[node]) return node;
        return find(parent[node]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            parent[b] = a;
        }
    }
};

int main() {
	int n , m;
    cin >> n >> m;
    vector<vector<int>> adj;
    for(int i = 0; i < m; i++) {
        int u , v , wt;
        cin >> u >> v >> wt;
        vector<int> temp;
        temp.push_back(wt);
        temp.push_back(u);
        temp.push_back(v);
        adj.push_back(temp);
    }

    int sum = 0;
    sort(adj.begin(), adj.end());
    DSU ds(n + 1);

    for(vector<int> current: adj) {
        int wt = current[0];
        int u = current[1];
        int v = current[2];
        if(ds.find(u) != ds.find(v)) {
            sum += wt;
            ds.unite(u, v);
            cout << u << " " << v << endl;
        }
    }
    cout << sum << endl;
}