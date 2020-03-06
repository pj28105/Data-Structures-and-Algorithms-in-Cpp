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
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define deb(...)
#endif

/* 
Note ->
    1) Assuming 1-based Indexing
    2) Tree has N - 1 edges
    3) Using se(Unordered Set) for getting the root of
    the tree.
    Tested Status -> Negative
*/

int power(int a,int b){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a;
        }
        b = b >> 1;
        a = a * a;
    }
    return res;
}

void dfs(int root,int **dp,vector<int> g[],int lvl[],int parent,int maxL){
    // if it is a root node make lvl = 0
    if(parent == -1){
        lvl[root] = 0;
    }else{
        lvl[root] = lvl[parent] + 1;
    }
    dp[root][0] = parent;
    for(int j = 1; j <= maxL; j++){
        if(dp[root][j - 1] != -1){
            dp[root][j] = dp[dp[root][j - 1]][j - 1];
        }
    }
    for(int v : g[root]){
        dfs(v,dp,g,lvl,root,maxL);
    }
    return;
}

int lca(int a,int b,int maxL,int **dp,int lvl[]){
    if(lvl[a] < lvl[b]){
        swap(a,b);
    }
    int diff = lvl[a] - lvl[b];
    for(int i = maxL; i >= 0; i--){
        int currPow = power(2,i);
        if(currPow <= diff){
            diff -= currPow;
            a = dp[a][i];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = maxL; i >= 0; i--){
        if(dp[b][i] != -1 && dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main(void){
    int n,a,b,maxL;
    cin >> n;
    maxL = (int)ceil(log2(n));
    vector<int> g[n + 1];
    unordered_set<int> se;
    for(int i = 1; i <= n; i++){
        se.insert(i);
    }
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        g[a].push_back(b);
        se.erase(b);
    }
    int **dp = new int *[n + 1],lvl[n + 1],root = *se.begin();
    for(int i = 0; i <= n; i++){
        dp[i] = new int [maxL + 1];
        for(int j = 0; j <= maxL; j++){
            dp[i][j] = -1;
        }
    }
    dfs(root,dp,g,lvl,-1,maxL);
    int q;
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << lca(a,b,maxL,dp,lvl) << endl;
    }
}