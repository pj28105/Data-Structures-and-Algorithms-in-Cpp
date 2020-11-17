#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

    Note-> This is easiest way for finding cycle in directed graph.
    Solution is based upon khans's algorightm for topological sorting.

    Article link->
    https://www.geeksforgeeks.org/detect-cycle-in-a-directed-graph-using-bfs/

    Youtube video link->
    https://www.youtube.com/watch?v=tFpvX8T0-Pw

    Tested on GFG
*/

bool isCyclic(int n, vector<int> g[]){
    int indeg[n];
    memset(indeg,0,sizeof(indeg));
    for(int i = 0; i < n; i++){
        for(int v : g[i]){
            indeg[v]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    int vCount = 0;
    while(!q.empty()){
        int curr = q.front();
        vCount++;
        q.pop();
        for(int v : g[curr]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }
    return vCount == n ? false : true; 
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