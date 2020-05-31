#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://vjudge.net/problem/LightOJ-1122
    
    Tested on Light OJ
*/

int dp[11][11];

int solv(int n,int m,int a[],int prev){
    if(n == 0){
        return 1;
    }
    if(dp[n][prev] != -1){
        return dp[n][prev];
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(abs(prev - a[i]) <= 2){
            ans += solv(n - 1,m,a,a[i]);
        }
    }
    dp[n][prev] = ans;
    return ans;
}

int main(void){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int m,n;
        cin >> m >> n;
        int a[m];
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < m; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            ans += solv(n - 1,m,a,a[i]);
        }
        cout << "Case " << tt << ": " << ans << endl;
    }
    return 0;
}