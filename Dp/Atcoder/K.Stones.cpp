#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<bool>dp(k + 1);
    dp[0] = 0;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if((i - a[j]) >= 0 && !dp[i - a[j]]){
                dp[i] = 1;
                break;
            }
        }
    }
    if(dp[k]){
        cout << "First" << endl;
    }else
        cout << "Second" << endl;   
    return 0;
}