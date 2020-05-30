#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/editorial/
    
    Tested on Hackerearth
*/
void getDigits(int a,vector<int>&dig){
    while(a > 0){
        dig.push_back(a % 10);
        a = a/10;
    }
    return;
}

int dp[10][2][2];
int solv(int in,int tight,bool has3,vector<int>&dig){
    if(in == -1){
        return has3;
    }
    if(dp[in][tight][has3] != -1){
        return dp[in][tight][has3];
    }
    int limit = tight ? dig[in] : 9;
    int ans = 0;
    for(int i = 0; i <= limit; i++){
        if(i == limit && tight){
            ans += solv(in - 1,1,has3 || (i == 3),dig);
        }else{
            ans += solv(in - 1,0,has3 || (i == 3),dig);
        }
    }
    dp[in][tight][has3] = ans;
    return ans;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> dig;
        getDigits(n,dig);
        memset(dp,-1,sizeof(dp));
        int cnt = solv(dig.size() - 1,1,0,dig);
        cout << n - cnt << endl;
    }
    return 0;
}