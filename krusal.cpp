#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
public:
    //init parent[i] by i
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    //if not x use recursion to assign parent[i]=find[parent[i] then return
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    //union by find and if not return false else true after doing parent[yr]=xr
    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        parent[yr] = xr;
        return true;
    }
};

int main() {
    int n, m;  // n = number of nodes, m = number of edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;
    cout << "Enter each edge as: u v weight\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    
    sort(edges.begin(), edges.end());  // Sort by weight
    DSU dsu(n);
    int totalCost = 0;

    cout << "\nEdges in MST:\n";
    for (auto &[w, e] : edges) {
        int u = e.first, v = e.second;
        if (dsu.unite(u, v)) {
            cout << u << " - " << v << " = " << w << '\n';
            totalCost += w;
        }
    }

    cout << "Total cost: " << totalCost << '\n';
    return 0;
}
