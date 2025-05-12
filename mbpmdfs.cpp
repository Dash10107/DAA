
#include <bits/stdc++.h>
using namespace std;

bool bpm(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &matchV) {
    for(int v:adj[u]){
        if(!vis[v]){
            vis[v]=true;
            if (matchV[v]==-1 || bpm(matchV[v], adj, vis, matchV)){
                matchV[v]=u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(vector<vector<int>> &adj,int n,int m){
    vector<int>matchV(m+1,-1);
    int res = 0;
    for(int u=1;u<=n;u++){
        vector<bool>vis(m+1);
        if (bpm(u,adj,vis,matchV))res++;
    }
    return res;
}

int main()
{
    int n,m,e;
    cout<<"Enter no of nodes in u and v  : ";
    cin>>n>>m;
    cout<<"Enter no of edges : ";
    cin>>e;
    
    vector<vector<int>> adj(n + 1); // adjacency list for U side

    cout << "Enter each edge (u v) meaning U[u] is connected to V[v]:\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // u in U, v in V
    }

    cout << "Maximum Bipartite Matching: " << maxBPM(adj, n, m) << endl;
    

    return 0;
}
