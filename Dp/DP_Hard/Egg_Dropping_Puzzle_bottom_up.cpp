#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
    
    Tested on GFG
*/

int eggDrop(int n, int k) {
    int dp[n + 1][k + 1];
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i == 1){
                dp[i][j] = j;
                continue;
            }
            int currans = INT_MAX;
            for(int l = 1; l <= j; l++){
                currans = min(1 + max(dp[i - 1][l - 1],dp[i][j - l]),currans);
            }
            dp[i][j] = currans;
        }
    }
    return dp[n][k];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;

        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}