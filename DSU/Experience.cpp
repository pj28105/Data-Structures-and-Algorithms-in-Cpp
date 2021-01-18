#include <iostream>
#include <iomanip>
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
#include <numeric>
#include <utility>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// Dirty Fix
// #define int long long

/*
    Problem link->
        https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
    
    Tested on Codeforces
*/

class DSU{
    /*
        Note :
            1) union_them() function returns true if components are different otherwise it returns false.
            2) This DSU implementation is based on union by rank and path compression.
    */
    public:
        int size;
        vector<int>parent,rank,pts;
        DSU(int size){
            parent.resize(size);
            rank.resize(size);
            pts.resize(size);
            for(int i = 0; i < size; i++){
                rank[i] = 0;
                pts[i] = 0;
                parent[i] = i;
            }
        }
        int find(int curr){
            if(parent[curr] == curr){
                return curr;
            }
            return find(parent[curr]);
        }
        bool union_them(int x,int y){
            int parentX = find(x);
            int parentY = find(y);
            if(parentX == parentY){
                return false;
            }
            if(rank[parentX] > rank[parentY]){
                parent[parentY] = parentX;
                pts[parentY] -= pts[parentX];
            }else if(rank[parentY] > rank[parentX]){
                parent[parentX] = parentY;
                pts[parentX] -= pts[parentY];
            }else{
                parent[parentX] = parentY;
                pts[parentX] -= pts[parentY];
                rank[parentY]++;
            }
            return true;
        }
        int findVal(int curr){
            if(parent[curr] == curr){
                return pts[curr];
            }
            return pts[curr] + findVal(parent[curr]);
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
    DSU dsu(n);
    string s;
    int x,y;
    while(q--){
        cin >> s;
        if(s[0] == 'j'){
            cin >> x >> y;
            x--,y--;
            dsu.union_them(x,y);
        }else if(s[0] == 'a'){
            cin >> x >> y;
            x--;
            dsu.pts[dsu.find(x)] += y; 
        }else{
            cin >> x;
            x--;
            cout << dsu.findVal(x) << endl;
        }
    }
    return 0;
}