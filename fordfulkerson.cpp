
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
    int e,v;
    cout<<"Enter no of vertices and edges : ";
    cin>>v>>e;
    //using adjaceny matrix for ease 
    vector<vector<int>> adj(v, vector<int>(v, 0));
    cout << "Enter each edge as a pair of vertices with weight (u v w):" << endl;
    for (int i = 0; i < e; i++) {
        int u, w,wt;
        cin >> u >> w>>wt;
        adj[u][w]=wt;
    }
    int s,t;
    cout<<"Enter the source and sink node : ";
    cin>>s>>t;
    cout<<"Maximum Flow Using Ford Fulkerson : "<<fordfulkerson(adj,s,t);
    
    

    return 0;
}
