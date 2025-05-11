#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int prims(vector<vector<pair<int,int>>> &adj,int V){
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int>vis(V,0);
    vector<pair<int, int>> parent(V, {INT_MAX, -1});
    parent[0].first =0;
    int S = 0;
    pq.push({0,0});
    while (!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int weight = it.first;
        int node = it.second;
        if (vis[node]==1) continue;
        vis[node]=1;
        S+=weight;
        for (auto it:adj[node]){
            int v = it.first;
            int we = it.second;
            if (!vis[v] && we<parent[v].first){
                parent[v]={we,node};
                pq.push({we,v});
            }
        }
    }
    
    cout << "\nEdges in MST:\n";
    for (int i = 1; i < V; i++) {
        if (parent[i].second != -1) {
            cout << parent[i].second << " - " << i << " (Weight: " << parent[i].first << ")\n";
        }
    }
    return S;
    
}

int main() {
 auto start = high_resolution_clock::now();
    
    int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<pair<int,int>>> adj(v + 1);  // 1-based indexing

    cout << "Enter each edge as a pair of vertices with weight (u v w):" << endl;
    for (int i = 0; i < e; i++) {
        int u, w,wt;
        cin >> u >> w>>wt;
        adj[u].push_back({w,wt}); // directed edge u -> w with weight wt
        adj[w].push_back({u, wt});
    }

    int res = prims(adj,v);
    

    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(end - start);
    cout<<"Answer : "<<res<<endl;
    cout << "Time taken: " << duration.count() << " ms\n";

    cout << endl;
    return 0;
}
