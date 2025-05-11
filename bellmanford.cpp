#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> bellmanford(vector<vector<int>> &edges,int V,int S){
    vector<int> dis(V+1,INT_MAX);
    dis[S]=0;
    for(int i=0;i<V-1;i++){
        for (auto it:edges){
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            if (dis[u]!=INT_MAX && dis[u]+weight<dis[v]){
                dis[v]=dis[u]+weight;
            }
        }
    }
    for (auto it:edges){
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            if (dis[u]!=INT_MAX && dis[u]+weight<dis[v]){
                return {-1};
            }
    }
    
    return dis;
    
}
int main() {
 auto start = high_resolution_clock::now();
    
    int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> edges; 

    cout << "Enter each edge as a pair of vertices with weight (u v w):" << endl;
    for (int i = 0; i < e; i++) {
        int u, w,wt;
        cin >> u >> w>>wt;
        edges.push_back({u,w,wt});
    }
    vector<int> res = bellmanford(edges,v,1);
    cout << "\nShortest distances from source node 1:\n";
    if (res[0]==-1){
        cout<<"Negative Cycle Detected"<<endl;
        return 0;
    }
    for (int i = 1; i <= v; i++) {
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
