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
}q[300000];

int tree[4*30004];

int query(int st,int se,int si,int l,int r){
    if(se < l || r < st){
        return 0;
    }
    if(l <= st && se <= r){
        return tree[si];
    }
    int mid = (st + se) >> 1;
    return query(st,mid,2 * si + 1,l,r) + query(mid + 1,se,2 * si + 2,l,r);
}

void update(int st,int se,int si,int in){
    if(st == se && se == in){
        tree[si] = 1;
        return;
    }
    int mid = (st + se) >> 1;
    if(mid >= in && st <= in){
        update(st,mid,2 * si + 1,in);
    }else{
        update(mid + 1,se,2 * si + 2,in);
    }
    tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
    return;
}

signed main(void)
{
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
            ans[q[i].in] = query(0,n - 1,0,q[i].l,q[i].r);
        }else{
            update(0,n - 1,0,q[i].in);
        }
    }
    for(int i : ans){
        cout << i << endl;
    }
    return 0;
}