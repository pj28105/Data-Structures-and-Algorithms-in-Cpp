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

const int m = 1e9 + 7;
const int p = 31;
int distinctEchoSubstrings(string text) {
    long long hash[text.length()];
    long long pow_p[text.length()];
    pow_p[0] = 1;
    for(int i = 1; i < text.length(); i++){
        pow_p[i] = (pow_p[i - 1] * p) % m;
    }
    for(int i = 0; i < text.length(); i++){
        hash[i] = (i - 1) < 0 ? 0 : hash[i - 1];
        hash[i] = ((hash[i] % m) * (p)) % m;
        hash[i] = (hash[i] + int(text[i])) % m;
    }
    int ans = 0;
    unordered_set<int>hash_set;
    for(int i = 0; i < text.length(); i++){
        for(int j = i; (2*j - i + 1) < text.length(); j++){
            long long currhash = 0,nexthash = 0;
            if((i - 1) >= 0){
                currhash = (hash[j] - ((hash[i - 1] * pow_p[j - i + 1]) % m) + m) % m; 
            }else{
                currhash = hash[j];
            }
            nexthash = (hash[2*j - i + 1] - ((hash[j] * pow_p[j - i + 1]) % m) + m) % m;
            if(nexthash == currhash && hash_set.find(currhash) == hash_set.end()){
                int f = 1;
                for(int k = i,l = j + 1; k <= j; k++,l++){
                    if(text[k] != text[l]){
                        f = 0;
                        break;
                    }
                }
                if(f){
                    ans++;
                    hash_set.insert(currhash);
                }
            }
        }
    }
    return ans;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    string s;
    cin >> s;
    cout << distinctEchoSubstrings(s) << endl;       
    return 0;
}