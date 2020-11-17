#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

    Tested on GFG

    Use recursive over iterative version as it is easy to understand and easy to implement!
*/

bool dfs(int s,bool inStack[],bool vis[],vector<int> g[]){
    inStack[s] = 1;
    bool ans = 0;
    for(int v : g[s]){
        if(!vis[v]){
            if(!inStack[v]){
                ans = ans || dfs(v,inStack,vis,g);
            }else{
                return 1;
            }
        }
    }
    inStack[s] = 0;
    vis[s] = 1;
    return ans;
}

bool isCyclic(int n, vector<int> g[]){
    bool vis[n],inStack[n];
    memset(vis,0,sizeof(vis));
    memset(inStack,0,sizeof(inStack));
    bool ans = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ans = ans || dfs(i,inStack,vis,g);
        }
    }
    return ans;
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}