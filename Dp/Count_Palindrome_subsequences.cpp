// Counts Palindromic Subsequence in a given String
#include<iostream>
#include<cstring>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
    
    Tested on GFG
*/

int countPS(string str); 
int main()
{
   int t;
	cin>>t;
   while(t--)
	{
	    string str;
        cin>>str;
        cout<<countPS(str)<<endl;
    } 
}

int countPS(string s){
    int n = s.length();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                dp[i][j] = 1;
            }
            else if(s[i] == s[j]){
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            }else{
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    return dp[0][n - 1];
}
 