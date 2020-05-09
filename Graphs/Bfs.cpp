#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

    Note-> Remember mark visited when you push vertex to queue and always remember to
           mark initial vertex to visted.

    Assumptions->
        1)Graph is connected.
        2)Vertices are from 0 to N.

    Tested on GFG
*/

void bfs(int s, vector<int> g[], bool vis[], int N){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for(int v : g[curr]){
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}