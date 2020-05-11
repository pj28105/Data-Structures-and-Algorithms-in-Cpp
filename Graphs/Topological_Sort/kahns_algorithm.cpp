#include<bits/stdc++.h>
using namespace std;

/*
    Article link->
    https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

    Tested status false
*/

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
        vector<int>indeg(v);
        for(int i = 0; i < v; i++){
            for(int j : g[i]){
                indeg[j]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < v; i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int i : g[curr]){
                indeg[i]--;
                if(indeg[i] == 0)
                    q.push(i);
            }
        }
        if(ans.size() == v)
            for(int i : ans){
                cout << i << " ";
            }
        else   
            cout << "Graph is cyclic!" ;
        cout << endl;
    }
}