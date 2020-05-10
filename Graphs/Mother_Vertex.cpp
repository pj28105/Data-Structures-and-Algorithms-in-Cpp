#include <bits/stdc++.h> 
using namespace std; 

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/mother-vertex/1

    Perform DFS traversal of the given graph. While doing traversal keep track of last finished vertex ‘v’.
    If there exist mother vertex, then v must be one. Check if v is a mother vertex by performing DFS/BFS from v.

    Tested on GFG
*/


void dfs(int s,bool vis[],vector<int>g[]){
    vis[s] = 1;
    for(int v : g[s]){
        if(!vis[v])
            dfs(v,vis,g);
    }
    return;
}

int findMother(int n, vector<int> g[]) { 
    int last;
    bool vis[n];
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            last = i;
            dfs(i,vis,g);
        }
    }
    memset(vis,0,sizeof(vis));
    dfs(last,vis,g);
    for(int i = 0; i < n; i++){
        if(!vis[i])
            return -1;
    }
    return last;
} 

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}