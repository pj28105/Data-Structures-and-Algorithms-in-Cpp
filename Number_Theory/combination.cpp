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

/*
    Steps =>
    1. Compute factorial upto MAX
    2. For combination we have compute  (n!) / (r! (n - r)!)
    3. By Modulo properties this can be written as n! * INVMOD((r)!) * INVMOD((n - r)!)  INVMOD-> Modulo Inverse
    4. Use fermat little theorem to compute INVMOD() (See notes)

    Note-> This Program is not submitted anywhere
    Tested status -> false
*/


const int MAX = 2001;

ll fact[MAX],invfact[MAX];

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

 // func for computing factorial and modulo inverse of factorial
   
void preCompute(){
    fact[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
        invfact[i] = power(fact[i],mod - 2);
    }
}

// func for computing nCr 

ll comb(ll n,ll r){
    return (((fact[n] * invfact[r]) % mod) * invfact[n - r]) % mod;  
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    preCompute();
    cout << comb(2000,5) << endl;
    return 0;
}