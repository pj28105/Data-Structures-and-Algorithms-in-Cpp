#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1/?track=amazon-dynamic-programming&batchId=192
    
    Tested on GFG
*/

long long maximumAmount(int a[], int n) {
    long long dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                dp[i][j] = a[i];
            }else if((j - i + 1) == 2){
                dp[i][j] = max(a[j],a[i]);
            }else{
                int x = min(dp[i + 1][j - 1],dp[i + 2][j]);
                int y = min(dp[i][j - 2],dp[i + 1][j - 1]);
                dp[i][j] = max(a[i] + x,a[j] + y);
            }
        }
    }
    return dp[0][n - 1];
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << maximumAmount(a,n) << endl;
    }
}