#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://www.codechef.com/problems/WORDS1
        https://www.spoj.com/problems/WORDS1/

    Problem is based on Euler path.
        You have to check if there exists a euler path in directed Graph.

    Conditions for euler path in directed Graph->
        1) Vertex with (indegree - outdegree) = 1 should be at most 1.
        2) Vertex with (outdegree - indegree) = 1 should be at most 1.
        3) If you have a vertex who satisfy conditon no. 1 start a dfs from that vertex
            else pick any any vertex and start a dfs traversal if all nodes are visited with indegree > 0
            then Graph has euler path else eluer path doesn't exisits!
    
    Note-> For this question all vertices must be visited!
*/

void dfs(int s,unordered_map<int,vector<int>>&ma,vector<bool>&vis){
    vis[s] = 1;
    for(auto i : ma[s]){
        if(!vis[i]){
            dfs(i,ma,vis);
        }
    }
    return;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a[n];
        unordered_map<int,vector<int>>ma;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ma[(a[i].front() - 'a')].push_back((a[i].back() - 'a'));
        }
        int inCount = 0,outCount = 0,st = (*ma.begin()).first;
        bool isPossible = 1;
        vector<int> indeg(26);
        for(auto i : ma){
            for(auto j : i.second){
                indeg[j]++;
            }
        }
        for(auto i : ma){
            int val = i.second.size() - indeg[i.first];
            if(val == 1){
                outCount++;
                st = i.first;
            }else if(val == -1){
                inCount++;
            }else if(val != 0){
                isPossible = 0;
                break;
            }
        }
        vector<bool>vis(26);
        dfs(st,ma,vis);
        for(int i = 0; i < 26; i++){
            if(!vis[i] && ma.find(i) != ma.end()){
                isPossible = 0;
                break;
            }
        }
        if(isPossible && inCount <= 1 && outCount <= 1){
            cout << "Ordering is possible." << endl;
        }else{
            cout << "The door cannot be opened." << endl;
        }
    }
}