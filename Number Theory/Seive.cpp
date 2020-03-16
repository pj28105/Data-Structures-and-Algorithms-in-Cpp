// PJ28105
// MARK 2

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
#define tc int t; cin >> t; while(t--)
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ERR
#ifdef ERR
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define deb(...)
#endif

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

void seive(int n,bool primes[]){
    memset(primes,1,(n + 1) * sizeof(bool));
    primes[0] = primes[1] = 0;  
    for(int i = 2; i * i <= n; i++){
        if(primes[i]){
            for(int j = i * i; j <= n; j+= i){
                primes[j] = 0;
            }
        }
    }
    return;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
       // freopen("../in.txt","r",stdin);
    #endif
    bool primes[10004];
    seive(10000,primes);
    tc{
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++){
            if(primes[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}