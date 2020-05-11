#include<bits/stdc++.h>
using namespace std;

/*
    Article link->
    https://www.geeksforgeeks.org/topological-sorting/

    Tested status false
*/

void dfs(stack<int>&ans,int s,vector<int>g[],vector<bool>&vis){
    vis[s] = 1;
    for(int v : g[s]){
        if(!vis[v])
            dfs(ans,v,g,vis);
    }
    ans.push(s);
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int v,e;
        cin >> v >> e;
        vector<int>g[v];
        for(int i = 0; i < e; i++){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
        }
        vector<bool> vis(v);
        stack<int> ans;
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                dfs(ans,i,g,vis);
            }
        }    
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
    }
}