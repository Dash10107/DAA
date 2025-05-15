#include <bits/stdc++.h>
using namespace std;

vector<int> bellman(vector<tuple<int, int, int>> &edges, int source, int v) {
    vector<int> dis(v, INT_MAX);
    dis[source] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (auto [u, vt, wt] : edges) {
            if (dis[u] != INT_MAX && dis[u] + wt < dis[vt]) {
                dis[vt] = dis[u] + wt;
            }
        }
    }

    // Check for negative weight cycles
    for (auto [u, vt, wt] : edges) {
        if (dis[u] != INT_MAX && dis[u] + wt < dis[vt]) {
            return {-1}; // Signal negative cycle
        }
    }

    return dis; // ✅ This must be outside the loop
}

int main() {
    int e, v;
    cin >> e >> v;
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < e; i++) {
        int u, vt, wt;
        cin >> u >> vt >> wt;
        edges.push_back({u, vt, wt});
    }

    int source;
    cin >> source;
    vector<int> res = bellman(edges, source, v);

    if (res.size() == 1 && res[0] == -1) {
        cout << "Negative Cycle\n";
    } else {
        cout << "Shortest distances from node " << source << ":\n";
        for (int i = 0; i < v; i++) {
            if (res[i] == INT_MAX)
                cout << "INF ";
            else
                cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
