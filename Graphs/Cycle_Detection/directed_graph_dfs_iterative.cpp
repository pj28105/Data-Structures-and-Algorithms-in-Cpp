#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

    Tested on GFG
*/


bool dfs(int s,bool inStack[],bool vis[],vector<int> g[]){
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(inStack[curr]){
            inStack[curr] = 0;
            vis[curr] = 1;
        }else{
            st.push(curr);
            inStack[curr] = 1;
            for(int v : g[curr]){
                if(!vis[v]){
                    if(inStack[v]){
                        return 1;
                    }else{
                        st.push(v);
                    }
                }
            }
        }
    }
    return 0;
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