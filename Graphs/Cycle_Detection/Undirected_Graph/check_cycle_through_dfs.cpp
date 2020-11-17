#include<bits/stdc++.h>

using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

    Most simplest way to find cycle in an undirected graph.
    This solution also help us to detect self loop in graph.

    Tested on GFG
*/

bool dfs(int s,bool vis[],vector<int>g[],int parent){
    vis[s] = 1;
    bool hasCycle = 0;
    for(int v : g[s]){
        if(vis[v] && v != parent){
            return 1;
        }
        if(!vis[v])
            hasCycle = hasCycle || dfs(v,vis,g,s);
    }
    return hasCycle;
}

bool isCyclic(vector<int> g[], int n){
    bool vis[n];
    bool hasCycle = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            hasCycle = hasCycle || dfs(i,vis,g,-1);
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
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}