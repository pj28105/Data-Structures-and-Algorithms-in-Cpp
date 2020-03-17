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

struct offline{
    int l,r,in,val;
    bool isQuery = false; 
}q[230005];

int bit[30005];

int query(int i){
    int sum = 0;
    for(; i > 0; i -= i&(-i)){
        sum += bit[i];
    }
    return sum;
}

void update(int i){
    for(; i < 30005; i+=i&(-i)){
        bit[i] += 1;
    }
    return;
}

signed main(void){
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin); 
    #endif
    int n,siz = 0;
    cin >> n;
    for(siz = 0; siz < n; siz++){
        cin >> q[siz].val;
        q[siz].l = numeric_limits<int>::max();
        q[siz].in = siz;
    }
    int qq;
    cin >> qq;
    for(int i = 0; i < qq; i++){
        cin >> q[siz].l >> q[siz].r >> q[siz].val; 
        q[siz].l --;
        q[siz].r--;
        q[siz].isQuery = true;
        q[siz].in = i;
        siz++;
    }
    vector<int> ans(qq);
    sort(q,q + siz,[](offline a,offline b) -> bool {
        if(a.val != b.val)
            return a.val > b.val;
        return a.l < b.l;
    });
    for(int i = 0; i < siz; i++){
        if(q[i].isQuery){
            ans[q[i].in] = query(q[i].r + 1) - query(q[i].l);
        }else
            update(q[i].in + 1);
    }
    for(int i : ans){
        cout << i << endl;
    }
    return 0;
}