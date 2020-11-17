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

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
       freopen("../in.txt","r",stdin);
    #endif
    tc{
        int n,sum = 0;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        bool dp[2][sum + 1];
        memset(dp,0,sizeof(dp));
        dp[1][0] = 1;
        for(int i = 0; i < n; i++){
            int currRow = i & 1;
            for(int j = 0; j < a[i]; j++){
                dp[currRow][j] = dp[currRow ^ 1][j];
            }
            for(int j = a[i]; j <= sum; j++){
                dp[currRow][j] = dp[currRow ^ 1][j] || dp[currRow ^ 1][j - a[i]];
            }
        }
        int ans = 0;
        for(int j = sum/2; j >= 0; j--){
            if(dp[(n - 1) & 1][j]){
                ans = abs((sum - j) - j);
                break;
            }
        }
        cout << ans << endl;
    }      
    return 0;
}