#include<bits/stdc++.h>
using namespace std;


void dfs(int s,vector<int> g[],vector<int>&dp){
    int currAns = 0;
    for(int v : g[s]){
        if(dp[v] == -1){
            dfs(v,g,dp);
        }
        currAns = max(currAns,1 + dp[v]);
    }
    dp[s] = currAns;
    return;
}

int main(void){
    int v,e;
    cin >> v >> e;
    vector<int>g[v];
    for(int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
    }
    vector<int> dp(v,-1);
    int ans = 0;
    for(int i = 0; i < v; i++){
        if(dp[i] == -1){
            dfs(i,g,dp);
        }   
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
}