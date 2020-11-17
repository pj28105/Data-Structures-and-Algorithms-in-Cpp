/*
PJ28105
    ###
    #
    ###
      #
    ### 
*/ 

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits.h>
#include <math.h>
#include <utility>
#include <algorithm>
using namespace std;
 
#define mod 1000000007
#define ll long long
#define tc int t; cin >> t; for(int tt = 1; tt <= t; tt++)
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ERR
#ifdef ERR
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define deb(...)
#endif

// Dirty Fix
// #define int long long


ll power(ll a,ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = ((res % mod) * (a % mod)) % mod;
        }
        b = b >> 1;
        a = ((a % mod) * (a % mod)) % mod; 
    }
    return res;
}

int dp[100][3000];

int solv(int a[],int i,int n,int sum,int total){
    if(i >= n){
        return abs(sum - (total - sum));
    }
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    int ans = min(solv(a,i + 1,n,sum - a[i],total),solv(a,i + 1,n,sum,total));
    dp[i][sum] = ans;
    return ans;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
      //  freopen("../in.txt","r",stdin);
    #endif
    tc{
        int n,sum = 0;
        cin >> n;
        int a[n];
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        cout << solv(a,0,n,sum,sum) << endl;
    }      
    return 0;
}