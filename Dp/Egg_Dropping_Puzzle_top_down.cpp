#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
    
    Tested on GFG
*/

int dp[11][51];
int solv(int n,int k){
    if(n == 1){
        return k;
    }
    if(k == 0 || k == 1){
        return k;
    }
    if(dp[n][k] != -1){
        return dp[n][k];
    }
    int ans = INT_MAX;
    for(int i = 1; i <= k; i++){
        ans = min(ans,1 + max(solv(n - 1,i - 1),solv(n,k - i)));
    } 
    dp[n][k] = ans;
    return ans;
}
int eggDrop(int n, int k) {
    memset(dp,-1,sizeof(dp));
    return solv(n,k);
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