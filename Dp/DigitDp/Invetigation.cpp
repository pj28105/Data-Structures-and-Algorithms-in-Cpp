#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://vjudge.net/problem/LightOJ-1068
    
    Tested on LightOJ
*/
void getDigits(int a,vector<int>&dig){
    while(a > 0){
        dig.push_back(a % 10);
        a = a/10;
    }
    return;
}

long long power(long long a,long long b){
    long long res = 1;
    while(b > 0){
        if(b & 1)
            res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
}

int dp[10][2][95][100];
int solv(int in,int tight,int sum,int rem,int k,vector<int>&dig){
    if(in == -1){ 
        if(rem % k == 0 && sum % k == 0){
            return 1;
        }
        return 0;
   }
   if(dp[in][tight][sum][rem] != -1){
       return dp[in][tight][sum][rem];
   }
   int limit = tight ? dig[in] : 9;
   int ans = 0;
   for(int i = 0; i <= limit; i++){
       if(i == limit && tight){
           ans += solv(in - 1,1,sum + i,(rem + i * (long long)power(10,in)) % k,k,dig);
       }else{
           ans += solv(in - 1,0,sum + i,(rem + i * (long long)power(10,in)) % k,k,dig);
       }
   }
   dp[in][tight][sum][rem] = ans;
   return ans;
}

int main(void){
    int t;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int a,b,k;
        cin >> a >> b >> k;
        if(k > 99){
            cout << "Case " << tt << ": "<< 0 << endl;
            continue; 
        }
        vector<int>diga,digb;
        getDigits(a - 1,diga);
        getDigits(b,digb);
        memset(dp,-1,sizeof(dp));
        int r = solv(digb.size() - 1,1,0,0,k,digb);
        memset(dp,-1,sizeof(dp));
        int l = solv(diga.size() - 1,1,0,0,k,diga);
        cout << "Case " << tt << ": "<< r - l << endl; 
    }
    return 0;
}