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

int bit[30004];

void update(int i){
    for(; i < 30004; i += i&(-i)){
        bit[i] += 1;
    }
    return;
}

int query(int i){
    int sum = 0;
    for(; i > 0; i -= i&(-i)){
        sum += bit[i];
    }
    return sum;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    tc{
        memset(bit,0,sizeof(bit));
        int n;
        cin >> n;
        unordered_map<string,int>m;
        string s[n];
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        for(int i = 0; i < n; i++){
            string aux;
            cin >> aux;
            m[aux] = i + 1;
        }
        for(int i = 0; i < n; i++){
            a[i] = m[s[i]];
        }
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            ans += query(a[i]);
            update(a[i]);
        }
        cout << ans << endl;
    }      
    return 0;
}