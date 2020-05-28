#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://www.spoj.com/problems/BUGLIFE/
    
    Tested on SPOJ
*/
bool dfs(vector<int>g[],vector<int>&color,int s,int c){
    color[s] = c;
    for(int v : g[s]){
        if(color[v] == -1){
            if(!dfs(g,color,v,1 ^ c)){
                return 0;
            }
        }
        else if(color[v] == c){
            return 0;
        }
    }
    return 1;
}

int main(void){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int v,e;
        cin >> v >> e;
        vector<int>g[v];
        for(int i = 0; i < e; i++){
            int a,b;
            cin >> a >> b;
            a--,b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int>color(v,-1);
        bool isBipartite = 1;
        for(int i = 0; i < v; i++){
            if(color[i] == -1){
                isBipartite = isBipartite && dfs(g,color,i,1);
            }
            if(!isBipartite){
                break;
            }
        }
        cout << "Scenario #" << tt << ":" << endl;
        if(!isBipartite){
            cout << "Suspicious bugs found!" << endl;
        }else{
            cout << "No suspicious bugs found!" << endl;
        }
    }
}