#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    Problem link->
        https://www.spoj.com/problems/HOLI/

    Tested on Spoj
    Recommended By Love Babbar!
*/
int dfs(int s,vector<vector<pair<int,int>>>&g,unordered_map<int,int>&dp,ll &ans){
    dp[s] = 0;
    int visCount = 0;
    for(pair<int,int>v : g[s]){
        int currCount = 0;
        if(dp.find(v.first) == dp.end()){
            currCount = dfs(v.first,g,dp,ans);
            ans += v.second * (2 * min((int)g.size() - currCount,currCount));
        }else{
            currCount = dp[v.first];
            ans += v.second * (2 * min((int)g.size() - currCount,currCount));
        }
        visCount += currCount;
    }
    dp[s] = visCount + 1;
    return visCount + 1;
}

int main(void){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int v;
        cin >> v;
        vector<vector<pair<int,int>>>g(v);
        for(int i = 0; i < (v - 1); i++){
            int a,b,w;
            cin >> a >> b >> w;
            a--,b--;
            g[a].push_back({b,w});
            g[b].push_back({a,w});
        }
        unordered_map<int,int> dp;
        ll ans = 0;
        dfs(0,g,dp,ans);
        cout << "Case #" << tt << ": " << ans << endl;
    }
}