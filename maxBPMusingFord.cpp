
#include <bits/stdc++.h>
using namespace std;

//bfs for augmentted path on residual graph
//parent array for recreating the path later
bool bfs(vector<vector<int>> &adj,int source,int sink,vector<int> &parent){
    int n = adj.size();
    vector<bool>vis(n,false);
    queue<int> q;
    q.push(source);
    vis[source]=true;
    parent[source]=-1;
    
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v = 0;v<n;v++){
            if (!vis[v] && adj[u][v]>0){
                //if v == sink then return else keep going on the path 
                if (v==sink){
                    parent[sink]=u;
                    return true;
                }
                q.push(v);
                parent[v]=u;
                vis[v]=true;
            }
        }
        
    }
    return false;
}
int fordfulkerson(    vector<vector<int>> &adj,int source,int sink){
int n = adj.size(); 
vector<vector<int>> capacity = adj; 
vector<int> parent(n);
int maxFlow = 0;
//while there is augmentted path to sink from source keep counting 
while (bfs(capacity,source,sink,parent)){
    int pathFlow = INT_MAX;
    int v = sink;
    //finding the min flow of the path using parent array
    while (v!=source){
        int u = parent[v];
        pathFlow = min(pathFlow,capacity[u][v]);
        v = u;
    }
    //actually reducing the path with the flow 
    v = sink;
    while (v!=source){
        int u = parent[v];
        capacity[u][v]-=pathFlow;
        capacity[v][u]+=pathFlow;
        v = u;
    }
    maxFlow+=pathFlow;
    
}

    return maxFlow;
}

int main()
{
    int n,m,e;
    cout<<"Enter no of nodes in u and v  : ";
    cin>>n>>m;
    cout<<"Enter no of edges : ";
    cin>>e;
        int V = n + m + 2;//adding source and sink
    int source = 0;
    int sink = V - 1;
    
    //using adjaceny matrix for ease 
    vector<vector<int>> adj(V, vector<int>(V, 0));
    cout << "Enter each edge as a pair of vertices with weight (u v:" << endl;
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u][n+w]=1;
    }
        // Connect source to all u nodes
    for (int i = 1; i <= n; i++)
        adj[source][i] = 1;

    // Connect sink to all v nodes
    for (int i = 1; i <= m; i++)
        adj[n + i][sink] = 1;
        
    cout << "Maximum Bipartite Matching: " << fordfulkerson(adj, source, sink) << endl;

    

    return 0;
}
