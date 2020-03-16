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

const int blk_siz = 175;
struct query{
    int l,r,in;
};
query q[200005];
int freq[1000006];

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int qq;
    cin >> qq;
    for(int i = 0; i < qq; i++){
        cin >> q[i].l >> q[i].r;
        q[i].in = i;
        q[i].l--;
        q[i].r--;
    }
    sort(q,q + qq,[](query a,query b) -> bool {
        if((a.l/blk_siz) != (b.l/blk_siz)){
            return (a.l/blk_siz) < (b.l/blk_siz);
        }
        return a.r < b.r;
    });
    vector<int> ans(qq);
    int ml = 0,mr = -1,currCount = 0;
    for(int i = 0; i < qq; i++){
        while(q[i].l > ml){
            freq[a[ml]]--;
            if(freq[a[ml]] == 0){
                currCount--;
            }
            ml++;
        }
        while(q[i].l < ml){
            ml--;
            freq[a[ml]]++;
            if(freq[a[ml]] == 1){
                currCount++;
            }
        }
        while(q[i].r > mr){
            mr++;
            freq[a[mr]]++;
            if(freq[a[mr]] == 1){
                currCount++;
            }
        }
        while(q[i].r < mr){
            freq[a[mr]]--;
            if(freq[a[mr]] == 0){
                currCount--;
            }
            mr--;
        }
        ans[q[i].in] = currCount;
    }
    for(auto i : ans){
        cout << i << endl;
    }
    return 0;
}