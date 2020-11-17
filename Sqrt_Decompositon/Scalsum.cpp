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
    Problem link->
        https://www.codechef.com/problems/SCALSUM
    
    Tested on Codechef!
*/

const ll mod = 1ll << 32;
const int MAX = 3*1e5 + 1;
vector<int>g[MAX],lvl[MAX];
vector<ll>cache[MAX];
ll wt[MAX],topWt[MAX];
int parent[MAX],maxlvl,idx[MAX],depth[MAX];
bool isComputed[MAX];

void dfs(int curr,int par,ll wtTillHere,int d){
    parent[curr] = par;
    depth[curr] = d;
    lvl[d].emplace_back(curr);
    topWt[curr] = (wtTillHere + ((wt[curr] * wt[curr]) % mod)) % mod;
    maxlvl = max(maxlvl,d);
    for(int i : g[curr]){
        if(i != par){
            dfs(i,curr,topWt[curr],d + 1);
        }
    }
}

ll query(int x,int y){
    ll result = 0;
    while(x != y && !isComputed[x]){
        result = (result + ((wt[x] * wt[y]) % mod)) % mod;
        x = parent[x];
        y = parent[y];
    }
    if(x == y){
        result = (result + topWt[x]) % mod;
    }else{
       result = (result + cache[depth[x]][idx[x] * lvl[depth[x]].size() + idx[y]]) % mod;
    }
    return result;
}

int main(void)
{
    ios;
    int n,x,y,q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> wt[i];
    }
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        g[x - 1].emplace_back(y - 1);
        g[y - 1].emplace_back(x - 1);
    }
    dfs(0,-1,0,0);
    int blk_siz = 80;
    for(int i = 1; i <= maxlvl; i += blk_siz){
        int minSize = lvl[i].size(),minIndex = i;
        for(int j = i + 1; j < (i + blk_siz); j++){
            if(minSize > lvl[j].size()){
                minSize = lvl[j].size();
                minIndex = j;
            }
        }
        int id = 0;
        for(int j : lvl[minIndex]){
            idx[j] = id++;
        }
        for(int j : lvl[minIndex]){
            for(int k : lvl[minIndex]){
                if(idx[j] <= idx[k])
                    cache[minIndex].emplace_back(query(j,k));
                else
                   cache[minIndex].emplace_back(cache[minIndex][idx[k] * minSize + idx[j]]);
            }
        }
        for(int j : lvl[minIndex]){
            isComputed[j] = 1;
        }
    }
    while(q--){
        cin >> x >> y;
        x--,y--;
        cout << query(x,y) << endl;
    }
    return 0;
}