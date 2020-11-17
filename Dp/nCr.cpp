// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/ncr-1587115620/1
    
    Tested on GFG
*/

int nCrModp(int, int);

int main() 
{ 
  int t, n, r;
  cin >> t;
  
  while(t--){
      cin >> n >> r;
      cout << nCrModp(n, r) << endl;
  }
  
  return 0; 
}

const int mod = 1e9 + 7;
int nCrModp(int n, int r) { 
    int dp[r + 1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        int limit = min(i,r);
        for(int j = limit; j >= 0; j--){
            if(j == 0 || j == i){
                dp[j] = 1;
            }else{
                dp[j] = (dp[j] + (long long)dp[j - 1])%mod;
            }
        }
    }
    return dp[r];
} 