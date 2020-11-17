#include<bits/stdc++.h>
using namespace std;

/*
    Article link->
        https://www.geeksforgeeks.org/optimal-strategy-for-a-game-set-2/?ref=rp

    Tested on GFG
*/

long long dp[101][101];

long long maximumAmount(int a[],int i,int j,long long sum){
    if((j - i + 1) == 2){
        return max(a[i],a[j]);
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = max((sum - maximumAmount(a,i + 1,j,sum - a[i])),(sum - maximumAmount(a,i,j - 1,sum - a[j])));
    return dp[i][j];
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        long long sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        memset(dp,-1,sizeof(dp));
        cout << maximumAmount(a,i,j,sum) << endl;
    }
}