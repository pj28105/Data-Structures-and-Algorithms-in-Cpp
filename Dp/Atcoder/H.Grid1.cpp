#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main(void){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> dp(r,vector<int>(c,0));
    string a[r];
    for(int i = 0; i < r; i++){
        cin >> a[i];
    }
    if(a[0][0] == '#' || a[r - 1][c - 1] == '#'){
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i < c; i++){
        if(a[0][i] == '.'){
            dp[0][i] = dp[0][i - 1];
        }
    }
    for(int i = 1; i < r; i++){
        if(a[i][0] == '.'){
            dp[i][0] = dp[i - 1][0];
        }
    }
    for(int i = 1; i < r; i++){
        for(int j = 1; j < c; j++){
            if(a[i][j] == '.'){
                dp[i][j] = (dp[i - 1][j] + (long long)dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[r - 1][c - 1] << endl;
}