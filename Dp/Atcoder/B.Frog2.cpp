#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long> dp(n,INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i >= j)
                dp[i] = min(dp[i],dp[i - j] + abs(a[i] - a[i - j]));
            else
                break;
        }
    }
    cout << dp[n - 1] << endl;
}