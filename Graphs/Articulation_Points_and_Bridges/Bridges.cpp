#include <bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

    Article link->
        https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
        
    Tested on GFG
*/

class Graph {
    int V;
    list<int> *adj;

  public:
    Graph(int V);
    int addEdge(int v, int w);
    bool isBridge(int u, int v);
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
int Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        int s, N;
        cin >> s >> N;
        Graph *g = new Graph(s);
        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            g->addEdge(u, v);
        }
        int a, b;
        cin >> a >> b;

        if (g->isBridge(a, b))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

int tim = 0;
void dfs(int s,vector<bool>&vis,vector<int>&par,vector<int>&low,vector<int>&disc,set<pair<int,int>>&se,list<int>*adj)
{
    vis[s] = 1;
    tim++;
    disc[s] = tim;
    low[s] = tim;
    for(int v : adj[s]){
        if(!vis[v]){
            par[v] = s;
            dfs(v,vis,par,low,disc,se,adj);
            low[s] = min(low[s],low[v]);
            if(disc[s] < low[v]){
                se.insert({ min(s,v),max(s,v) });
            }
        }else if(par[s] != v){
            low[s] = min(low[s],disc[v]);
        }
    }
}

bool Graph::isBridge(int u, int v) {
    tim = 0;
    set<pair<int,int>>bdg;
    vector<bool> vis(this->V);
    vector<int>par(this->V),low(this->V),disc(this->V);
    for(int i = 0; i < this->V; i++){
        if(!vis[i]){
            par[i] = -1;
            dfs(i,vis,par,low,disc,bdg,this->adj);
        }
    }
    return bdg.find({min(u,v),max(u,v)}) != bdg.end();
}