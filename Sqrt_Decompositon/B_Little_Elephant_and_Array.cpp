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

struct query{
    int l,r,in;
}q[100005];

const int blk_size = 318;

signed main(void)
{
    ios;
    // #ifndef ONLINE_JUDGE
    //    freopen("../in.txt","r",stdin);
    // #endif
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].in = i;
    }
    sort(q,q+m,[](query aa,query b) -> bool{
        if((aa.l/blk_size) != (b.l/blk_size))
            return (aa.l/blk_size) < (b.l/blk_size);
        return aa.r < b.r;
    });
    unordered_map<int,int>ma;
    unordered_set<int> se;
    vector<int> ans(m);
    int ml = 0,mr = -1,currAns = 0;
    for(int i = 0; i < m; i++){
        while(q[i].l > ml){
            ma[a[ml]]--;
            if(ma[a[ml]] == a[ml]){
                currAns += 1;
                se.insert(a[ml]);
            }else if(se.find(a[ml]) != se.end()){
                se.erase(a[ml]);
                currAns--;
            }
            ml++;
        }
        while(q[i].l < ml){
            ml--;
            ma[a[ml]]++;
            if(ma[a[ml]] == a[ml]){
              currAns += 1;
               se.insert(a[ml]);
            }else if(se.find(a[ml]) != se.end()){
                se.erase(a[ml]);
                currAns--;
            }
        }
        while(q[i].r > mr){
            mr++;
            ma[a[mr]]++;
            if(ma[a[mr]] == a[mr]){
                currAns += 1;
                se.insert(a[mr]);
            }else if(se.find(a[mr]) != se.end()){
                se.erase(a[mr]);
                currAns--;
            }
        }
        while(q[i].r < mr){
            ma[a[mr]]--;
            if(ma[a[mr]] == a[mr]){
                currAns += 1;
                 se.insert(a[mr]);
            }else if(se.find(a[mr]) != se.end()){
                se.erase(a[mr]);
                currAns--;
            }
            mr--;
        }
        ans[q[i].in] = currAns;
    }
    for(int i : ans){
        cout << i << endl;
    }
    return 0;
}