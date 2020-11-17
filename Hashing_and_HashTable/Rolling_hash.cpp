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

/*
    Use p = 31 for lowercase letters
    Use p = 53 for upper and lowercase letters
    This implementation of this problem-> https://leetcode.com/problems/rotate-string/
*/

const int m = 1e9 + 7;

bool rotatestring(string a,string b){
    if(a.length() != b.length())
        return 0;
    if(!a.length())
        return 1;
    int p = 31;
    string aux = a + a;
    int hash_of_b = 0;
    int pow_p[b.length()];
    pow_p[0] = 1;
    for(int i = 1; i < b.length(); i++){
        pow_p[i] = (pow_p[i - 1] * p) % m; 
    }
    for(int i = 0; i < b.length(); i++){
        hash_of_b = ((hash_of_b % m) + ((int(b[i]) * pow_p[b.length() - 1 - i]) % m)) % m;
    }
    int currhash = 0;
    for(int i = 0; i < b.length(); i++){
        currhash = ((currhash % m) + ((int(aux[i]) * pow_p[b.length() - 1 - i]) % m)) % m;
    }
    if(currhash == hash_of_b && aux.compare(0,b.length(),b) == 0)
        return 1;
    for(int i = b.length(); i < aux.length(); i++){
        currhash = (currhash - ((int(aux[i - b.length()]) * pow_p[b.length() - 1]) % m) + m) % m;
        currhash = ((currhash * pow_p[1]) % m + (int(aux[i]))) % m;
        if(currhash == hash_of_b && aux.compare(i - b.length() + 1,b.length(),b) == 0)
            return true;
    }
    return 0;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    string a,b;
    cin >> a >> b;
    cout << rotatestring(a,b) << endl;
    return 0;
}