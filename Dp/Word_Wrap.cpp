#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/word-wrap/0
    
    Tested on GFG
*/
typedef long long ll;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cin >> m;
        vector<ll>dp(n,INT64_MAX);
        vector<int> ans(n);
        ans[n - 1] = n;
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            int currw = -1;
            for(int j = i; j < n; j++){
                currw += a[j] + 1;
                if(currw > m){
                    break;
                }
                ll currCost = 0;
                if(j != n - 1)
                    currCost = (m - currw) * (m - currw) + dp[j + 1];
                if(dp[i] > currCost){   
                    dp[i] = currCost;
                    ans[i] = j + 1;
                }
            }
        }
        int i = 0;
        while(i < n){
            cout << i + 1 << " " << ans[i] << " ";
            i = ans[i];  
        }
        cout << endl;
    }
    return 0;
}