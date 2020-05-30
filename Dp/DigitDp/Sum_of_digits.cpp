#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Problem link->
        https://www.spoj.com/problems/CPCRC1C/

    Article link->
        https://www.geeksforgeeks.org/digit-dp-introduction/
    
    Tested on SPOJ
*/

void getDigits(int a,vector<int>&diga){
    while(a > 0){
        diga.push_back(a % 10);
        a = a/10;
    }
    return;
}

ll dp[10][90][2];

ll solv(int in,int sum,int tight,vector<int>&dig){
    if(in == -1){
        return sum;
    }
    if(dp[in][sum][tight] != -1){
        return dp[in][sum][tight];
    }
    ll ans = 0;
    int limit = tight ? dig[in] : 9;
    for(int i = 0; i <= limit; i++){
        if(i == limit && tight)
            ans += solv(in - 1,sum + i,1,dig);
        else
            ans += solv(in - 1,sum + i,0,dig);
    }
    dp[in][sum][tight] = ans;
    return ans;
}

int main(void){
    while(true){
        int a,b;
        cin >> a >> b;
        if(a == b && a == -1){
            return 0;
        }
        memset(dp,-1,sizeof(dp));        
        vector<int> diga,digb;
        getDigits(a - 1,diga);
        getDigits(b,digb);
        ll r = solv(digb.size() - 1,0,1,digb);
        memset(dp,-1,sizeof(dp));
        ll l = solv(diga.size() - 1,0,1,diga);
        cout << (r - l) << endl;
    }
}