#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s,t;
    cin >> s >> t;
    vector<vector<int>> dp(t.length(),vector<int>(s.length()));
    for(int i = 0; i < (int)t.length(); i++){
        for(int j = 0; j < (int)s.length(); j++){
            if(t[i] == s[j]){
                if(i > 0 && j > 0){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else
                    dp[i][j] = 1;
            }else{
                if(j > 0)
                    dp[i][j] = dp[i][j - 1];
                if(i > 0)
                    dp[i][j] = max(dp[i - 1][j],dp[i][j]);
            }
        //    cout <<  dp[i][j] << " ";      
        }
        // cout << endl;
    }
    string ans = "";
    int i = t.length() - 1,j = s.length() - 1;
    while(1){
        if(dp[i][j] == 0){
            break;
        }
        if(i > 0 && dp[i][j] == dp[i - 1][j]){
            i--;
        }else if(j > 0 && dp[i][j] == dp[i][j - 1]){
            j--;
        }
        else if(i > 0 && j > 0 && dp[i][j] == (1 + dp[i - 1][j - 1])){
            ans = t[i] + ans;
            i--,j--;
        }
        else{
            ans = t[i] + ans;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}