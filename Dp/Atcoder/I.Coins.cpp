#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    double ph[n]; 
    for(int i = 0; i < n; i++){
        cin >> ph[i];
    }
    vector<vector<double>>dp(n,vector<double>(n + 1));
    
    dp[0][0] = 1 - ph[0];
    dp[0][1] = ph[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= (i + 1); j++){
            dp[i][j] = (1 - ph[i]) * dp[i - 1][j];
            if(j > 0)
                dp[i][j] += ph[i] * dp[i - 1][j - 1];
        }
    }
    double ans = 0;
    int min_heads = ceil(n/2.0);
    for(int i = min_heads; i <= n; i++){
        ans += dp[n - 1][i];
    }
    cout << setprecision(10) << ans << endl;
}