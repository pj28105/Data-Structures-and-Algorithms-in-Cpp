#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://www.spoj.com/problems/BUGLIFE/
    
    Tested on SPOJ
*/
bool bfs(vector<int>g[],vector<bool>&vis,int s){
    queue<int>q;
    unordered_set<int>se[2];
    vis[s] = 1;
    se[0].insert(s);
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        int parColor = se[0].find(u) != se[0].end() ? 0 : 1;
        q.pop();
        for(int v : g[u]){
            if(se[0].find(v) == se[0].end() && se[1].find(v) == se[1].end()){
                se[1 ^ parColor].insert(v);
                vis[v] = 1;
                q.push(v);
            }else if(se[parColor].find(v) != se[parColor].end()){
                return 0;
            }
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
        vector<bool>vis(v);
        bool isBipartite = 1;
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                isBipartite = isBipartite && bfs(g,vis,i);
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