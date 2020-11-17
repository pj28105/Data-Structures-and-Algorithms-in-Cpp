// PJ28105

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

const int MAX = 31700;

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

vector<int> seive(void){
    bool primes[MAX];
    fill(primes,primes + MAX,true);
    primes[0] = primes[1] = false;
    for(int i = 2; i * i <= MAX; i++){
        if(primes[i]){
            for(int j = i * i; j < MAX; j += i){
                primes[j] = false;
            }
        }
    }
    vector<int> p;
    p.push_back(2);
    for(int i = 3; i < MAX; i += 2){
        if(primes[i])
            p.push_back(i);
    }
    return p;
}

void segmented_seive(vector<int>& p,int l,int r){
    vector<bool> primes(r - l + 1,true);
    for(int i = 0; (p.at(i) * (ll) p.at(i)) <= r; i++){
        int currPrime = p.at(i),base = (l/currPrime) * currPrime;
        if(base < l){
            base += currPrime;
        }
        for(int j = base; j <= r; j+= currPrime){
            primes.at(j - l) = false;
        }
        if(currPrime >= l)
        primes.at(currPrime - l) = true;
    }
    for(int i = 0; i < primes.size(); i++){
        if(primes.at(i) && (i + l) != 1 && (i + l) != 0)
            cout << i + l << endl;
    }
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    vector<int> p = seive();
    tc{
        int l,r;
        cin >> l >> r;
        segmented_seive(p,l,r);
    }
    return 0;
}