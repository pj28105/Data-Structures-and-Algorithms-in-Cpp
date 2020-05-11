#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

    BFS cycle detection logic is same as DFS cycle detection logic for undirected graphs.

    Tested on GFG
*/

bool bfs(int s,bool vis[],vector<int>g[],int par[]){
    queue<int>q;
    q.push(s);
    vis[s] = 1;
    par[s] = -1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int v : g[curr]){
            if(vis[v] && par[curr] != v){
                return 1;
            }
            if(!vis[v]){
                vis[v] = 1;
                par[v] = curr;
                q.push(v);
            }
        }
    }
    return 0;
}

bool isCyclic(vector<int> g[], int n){
    int parent[n];
    bool vis[n],hasCycle = 0;
    memset(vis,0,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            hasCycle = hasCycle || bfs(i,vis,g,parent);
        }
    }
    return hasCycle;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}