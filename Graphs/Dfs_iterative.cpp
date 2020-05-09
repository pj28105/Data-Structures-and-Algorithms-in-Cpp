#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

    Assumptions->
        1)Graph is connected.
        2)Vertices are from 0 to N.

    Tested on GFG
*/

void dfs(int s, vector<int> g[], bool vis[]){
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!vis[curr]){
            vis[curr] = 1;
            cout << curr << " ";
            for(int i = g[curr].size() - 1; i >= 0; i--){
               if(!vis[g[curr][i]])
                 st.push(g[curr][i]);
            }
        }
    }
    return;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,g,vis);
        
        cout<<endl;

    }
}