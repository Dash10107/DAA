#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int>djikstra(vector<vector<pair<int,int>>> &adj,int V,int S){
    vector<int>dis(V+1,INT_MAX);
    dis[S]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,S});
    while (!pq.empty()){
        int di = pq.top().first;
        int dest = pq.top().second;
        pq.pop();
        if (di > dis[dest]) continue;
        for(auto it:adj[dest]){
            int v = it.first;
            int wt = it.second;
            if (di+wt<dis[v]){
                dis[v]=di+wt;
                pq.push({dis[v],v});
                
            }
        }
    }
    return dis;
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
    }

    // cout << "\nAdjacency List Representation:" << endl;
    // for (int i = 1; i <= v; i++) {
    //     cout << i << ": ";
    //     for (auto it : adj[i]) {
    //         cout << "(" << it.first << ", " << it.second << ") ";
    //     }
    //     cout << endl;
    // }
    vector<int> res = djikstra(adj,v,1);
    cout << "\nShortest distances from source node 1:\n";
    for (int i = 1; i <= v; i++) {
        cout << "1 -> " << i << " = ";
        if (res[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << res[i] << "\n";
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms\n";

    cout << endl;
    return 0;
}
