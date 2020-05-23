#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(void){
    int n,w;
    cin >> n >> w;
    vector<pair<ll,ll>>a(n);
    ll max_val = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        max_val += a[i].second;
    }
    vector<vector<ll>> dp(2,vector<ll>(max_val + 1,INT_MAX));
    
    dp[0][0] = 0,dp[1][0] = 0;
    for(int i = 0; i < n; i++){
        int currRow = i & 1;
        for(int j = 0; j <= max_val; j++){
            if(a[i].second <= j){
                dp[currRow][j] = min(dp[currRow ^ 1][j],a[i].first + dp[currRow ^ 1][j - a[i].second]);
            }else
                dp[currRow][j] = min(dp[currRow ^ 1][j],dp[currRow][j]);
        }
    }
    int last_row = (n - 1) & 1;
    for(int i = max_val; i >= 0; i--){
        if(dp[last_row][i] <= w){
            cout << i << endl;
            break;
        }
    }
    return 0;
}