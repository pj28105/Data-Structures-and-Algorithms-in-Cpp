#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 85; 
vector<int>primes;

void getDigits(int a,vector<int>&dig){
    while(a > 0){
        dig.push_back(a % 10);
        a = a/10;
    }
    return;
}

void seive(){
    bool p[MAX];
    memset(p,1,sizeof(p));
    p[0] = p[1] = 0;
    for(int i = 2; i * i <= MAX; i++){
        if(p[i]){
            for(int j = i * i; j < MAX; j += i){
                p[j] = 0;
            }
        }
    }
    for(int i = 2; i < MAX; i++){
        if(p[i])
            primes.push_back(i);
    }
    return;
}

ll dp[10][MAX][2];

ll solv(int in,int sum,int tight,vector<int>&dig){
    if(sum == 0){
        return 1;
    }
    if(in == -1){
        return 0;
    }
    if(dp[in][sum][tight] != -1){
        return dp[in][sum][tight];
    }
    ll ans = 0;
    int limit = tight ? dig[in] : 9;
    for(int i = 0; i <= limit; i++){
        if(sum < i){
            break;
        }
        if(i == limit && tight)
            ans += solv(in - 1,sum - i,1,dig);
        else
            ans += solv(in - 1,sum - i,0,dig);
    }
    dp[in][sum][tight] = ans;
    return ans;
}

int main(void){
    seive();
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        vector<int>diga,digb;
        getDigits(a - 1,diga);
        getDigits(b,digb);
        memset(dp,-1,sizeof(dp));
        ll r = 0;
        for(int i : primes){
            r += solv(digb.size() - 1,i,1,digb);
        }
        memset(dp,-1,sizeof(dp));
        ll l = 0;
        for(int i : primes){
            l += solv(diga.size() - 1,i,1,diga);
        }
        cout << (r - l) << endl;
    }
    return 0;
}