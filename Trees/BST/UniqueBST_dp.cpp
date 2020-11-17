#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1/?track=amazon-bst&batchId=192

    This is dp solution of the problem it can also be solved using catalan numbers formula
        with fermats little theorem.(Check github repo for that)
*/

const int mod = 1e9 + 7;

unordered_map<int,int>dp;

int numTrees(int n) {
    if(n == 1 || n == 0)
        return 1;
        
    if(n == 2){
        return 2;
    }
    
    if(dp.find(n) != dp.end())
        return dp[n];
    
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        ans = (ans + (((long long)numTrees(i - 1) * numTrees(n - i)  ) % mod))%mod; 
    }
    dp[n] = ans;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"\n";
    }
}