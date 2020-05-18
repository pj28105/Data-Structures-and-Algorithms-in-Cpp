#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/
    
    Tested on Hackerearth
*/

void dfs(int s,vector<bool>&vis,vector<int>g[],stack<int>&st){
    vis[s] = 1;
    for(int i : g[s]){
        if(!vis[i])
            dfs(i,vis,g,st);
    }
    st.push(s);
}

void dfs2(int s,vector<bool>&vis,vector<int>&aux,vector<int>tg[]){
    vis[s] = 1;
    aux.push_back(s);
    for(int i : tg[s]){
        if(!vis[i])
            dfs2(i,vis,aux,tg);
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    int v,e;
    cin >> v >> e;
    vector<int> g[v],tg[v];
    for(int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        tg[b].push_back(a);
    }
    vector<bool>vis(v,0);
    stack<int> st;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i,vis,g,st);
        }
    }
    fill(vis.begin(),vis.end(),false);
    vector<vector<int>>comp;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!vis[curr]){
            vector<int> aux;
            dfs2(curr,vis,aux,tg);
            comp.push_back(aux);
        }
    }
    for(auto i : comp){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}