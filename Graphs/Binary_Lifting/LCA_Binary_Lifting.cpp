#include<bits/stdc++.h>
using namespace std;
/* 
Note ->
    1) Using se(Unordered Set) for getting the root of
    the tree.

    Problem link->
        https://www.spoj.com/problems/LCA/
        
    Tested on -> Spoj
*/

void dfs(int s,int parent,vector<int>&lvl,vector<vector<int>>&dp,vector<int>g[],int maxL){
    if(s == parent){
        lvl[s] = 0;
    }else{
        lvl[s] = lvl[parent] + 1;
    }
    dp[s][0] = parent;
    for(int i = 1; i <= maxL; i++){
        dp[s][i] = dp[dp[s][i - 1]][i - 1];
    }
    for(int v : g[s]){
        dfs(v,s,lvl,dp,g,maxL);
    }
    return;
}

int lca(int a,int b,vector<int>&lvl,vector<vector<int>>&dp,int maxL){
    if(lvl[b] > lvl[a]){
        swap(a,b);
    }
    int diff = lvl[a] - lvl[b];
    for(int i = maxL; i >= 0; i--){
        int currpow = (1ll << i);
        if(currpow <= diff){
            diff -= currpow;
            a = dp[a][i];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = maxL; i >= 0; i--){
        if(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int v;
        cin >> v;
        vector<int>g[v];
        unordered_set<int> se;
        for(int i = 0; i < v; i++){
            se.insert(i);
        }
        for(int i = 0; i < v; i++){
            int childNodes;
            cin >> childNodes;
            for(int j = 0; j < childNodes; j++){
                int ch;
                cin >> ch;
                ch--;
                g[i].push_back(ch);
                se.erase(ch);
            }
        }
        int root = *se.begin();
        int maxL = ceil(log2(v));
        vector<int>lvl(v);
        vector<vector<int>>dp(v,vector<int>(maxL + 1,-1));
        dfs(root,root,lvl,dp,g,maxL);
        int q;
        cin >> q;
        cout << "Case " << tt << ":" << endl;
        while(q--){
            int a,b;
            cin >> a >> b;
            a--,b--;
            cout << lca(a,b,lvl,dp,maxL) + 1 << endl;
        }
    }
}