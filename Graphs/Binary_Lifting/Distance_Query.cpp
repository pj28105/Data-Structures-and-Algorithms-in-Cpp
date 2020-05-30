#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://www.spoj.com/problems/DISQUERY/

    Tested on SPOJ
*/
void dfs(int s,int cost,int parent,vector<bool>&vis,vector<pair<int,int>>g[],vector<vector<int>>&dp
    ,vector<vector<pair<int,int>>>&dist,vector<int>&lvl,int maxL){
    
    vis[s] = 1;
    if(s == parent){
        lvl[s] = 0;
    }else{
        lvl[s] = lvl[parent] + 1;
    }
    dp[s][0] = parent;
    dist[s][0].first = cost;
    dist[s][0].second = cost;
    for(int i = 1; i <= maxL; i++){
        dp[s][i] = dp[dp[s][i - 1]][i - 1];
        dist[s][i].first = max(dist[dp[s][i - 1]][i - 1].first,dist[s][i - 1].first);
        dist[s][i].second = min(dist[dp[s][i - 1]][i - 1].second,dist[s][i - 1].second);
    }
    for(pair<int,int>v : g[s]){
        if(!vis[v.first]){
            dfs(v.first,v.second,s,vis,g,dp,dist,lvl,maxL);
        }
    }
    return;
}

pair<int,int> find(int a,int b,vector<vector<int>>&dp,vector<vector<pair<int,int>>>&dist,vector<int>&lvl,int maxL){
    if(lvl[a] < lvl[b]){
        swap(a,b);
    }
    int diff = lvl[a] - lvl[b];
    int ma = INT_MIN,mi = INT_MAX;
    for(int i = maxL; i >= 0; i--){
        int currpow = 1ll << i;
        if(currpow <= diff){
            diff -= currpow;
            ma = max(ma,dist[a][i].first);
            mi = min(mi,dist[a][i].second);
            a = dp[a][i];
        }
    }
    if(a == b){
       return {mi,ma};
    }
    for(int i = maxL; i >= 0; i--){
        if(dp[b][i] != dp[a][i]){
            ma = max({ma,dist[b][i].first,dist[a][i].first});
            mi = min({mi,dist[b][i].second,dist[a][i].second});
            b = dp[b][i];
            a = dp[a][i];
        }
    }
    ma = max({ma,dist[b][0].first,dist[a][0].first});
    mi = min({mi,dist[b][0].second,dist[a][0].second});
    return {mi,ma};
}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int v;
    cin >> v;
    int maxL = ceil(log2(v));
    vector<pair<int,int>>g[v];
    for(int i = 0; i < v - 1; i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--,b--;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    vector<bool>vis(v);
    vector<int> lvl(v);
    vector<vector<int>>dp(v,vector<int>(maxL + 1));
    vector<vector<pair<int,int>>>dist(v,vector<pair<int,int>>(maxL + 1));
    dfs(0,0,0,vis,g,dp,dist,lvl,maxL);
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        a--,b--;
        if(a == b){
            cout << "0 0" << endl;
            continue; 
        }
        pair<int,int> ans = find(a,b,dp,dist,lvl,maxL);
        cout << ans.first << " " << ans.second << endl; 
    }
    return 0;
}