#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://www.spoj.com/problems/LKS/

    Tested on SPOJ
*/
typedef long long ll;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll w,n;
    cin >> w >> n;
    ll val[n],wt[n];
    for(int i = 0; i < n; i++){
        cin >> val[i] >> wt[i];
    }
    ll dp[w + 1];
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n; i++){
        for(int j = w; j >= 0; j--){
            if(j >= wt[i]){
                dp[j] = max(dp[j],val[i] + dp[j - wt[i]]);
            }
        }
    }
    cout << dp[w] << endl; 
}