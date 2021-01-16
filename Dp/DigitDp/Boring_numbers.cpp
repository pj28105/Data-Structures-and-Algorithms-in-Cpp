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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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

/*
    Problem link->
        https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem
    
    Tested on Google Kickstart
*/

ll dp[20][2][2];

ll getBoringCount(string num){
    if(num.length() == 1){
        return ((num[0] - '0') + 1)/2;
    }
    memset(dp,0,sizeof(dp));
    int len = num.length();
    for(int i = len - 1; i >= 0; i--){
        for(int j = 0; j < 2; j++){
            int limit = (j == 0 ? 9 : (num[i] - '0'));
            for(int k = 0; k < 2; k++){
                for(int l = k; l <= limit; l += 2){
                    if(i == (len - 1)){
                        dp[i][j][k]++;
                    }else if(l < limit || j == 0){
                        dp[i][j][k] += dp[i + 1][0][k ^ 1];
                    }else{
                        dp[i][j][k] += dp[i + 1][j][k ^ 1];
                    }
                }
            }
        }
    }
    ll ans = dp[0][1][1];
    for(int i = 1; i < len; i++){
        ans += dp[i][0][1];
    }
    return ans;
}

string getString(ll n){
    string s = "";
    while(n > 0){
        int dig = n % 10;
        s.push_back(dig + '0');
        n = n/10;
    }
    reverse(s.begin(),s.end());
    return s;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    tc{
        ll l,r;
        cin >> l >> r;
        ll cntr = getBoringCount(getString(r));
        ll cntl = getBoringCount(getString(l - 1));
        cout << "Case #" << tt << ": ";
        cout << (cntr - cntl) << endl;
    }
    return 0;
}