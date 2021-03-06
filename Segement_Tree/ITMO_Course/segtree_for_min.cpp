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

struct SegmentTree{
    vector<int> tree;
    SegmentTree(int n){
        tree.assign(4*n,0);
    }
    void build(int a[],int s,int e,int si){
        if(s == e){
            tree[si] = a[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(a,s,mid,2*si + 1);
        build(a,mid + 1,e,2*si + 2);
        tree[si] = min(tree[2*si + 1], tree[2*si + 2]);
        return;
    }
    int query(int s,int e,int si,int l,int r){
        if(r < s || e < l){
            return INT_MAX;
        }
        if(l <= s && e <= r){
            return tree[si];
        }
        int mid = (s + e) >> 1;
        int ans = query(s,mid,2*si + 1,l,r);
        ans = min(ans,query(mid + 1,e,2*si + 2,l,r));
        return ans; 
    }
    void update(int s,int e,int si,int in,int val){
        if(s == e){
            tree[si] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if(in <= mid){
            update(s,mid,2*si + 1,in,val);
        }else{
            update(mid + 1,e,2*si + 2,in,val);
        }
        tree[si] = min(tree[2*si + 1], tree[2*si + 2]);
        return;
    }
};

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    int n,q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    SegmentTree st(n);
    st.build(a,0,n - 1,0);
    while(q--){
        int type,l,r;
        cin >> type >> l >> r;
        if(type == 1){
            st.update(0,n - 1,0,l,r);
        }else{
            cout << st.query(0,n - 1,0,l,r - 1) << endl;
        }
    }
    return 0;
}