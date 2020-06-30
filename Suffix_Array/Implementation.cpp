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

/*
    Problem link->
        https://codeforces.com/edu/course/2/lesson/2/1/practice/contest/269100/problem/A

    Tested on Codeforces
*/

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    string s;
    cin >> s;
    s += '$';
    ll k = 0,n = s.length();
    vector<int> p(n),c(n);

    // Computing for K == 0
    {
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; i++){
            a[i] = {s[i],i};
        }
        stable_sort(a.begin(),a.end());
        c[a[0].second] = 0;
        p[0] = a[0].second;
        for(int i = 1; i < int(a.size()); i++){
            p[i] = a[i].second;
            if(a[i].first == a[i - 1].first){
                c[a[i].second] = c[a[i - 1].second];
            }else{
                c[a[i].second] = 1 + c[a[i - 1].second];
            }
        }
    }
    while((1ll << k) < n){
        vector<pair<pair<int,int>,int>> a(n);
        for(int i = 0; i < n; i++){
            a[i] = {{c[i],c[(i + (1ll << k)) % n]},i};
        }     
        stable_sort(a.begin(),a.end());
        c[a[0].second] = 0;
        p[0] = a[0].second;
        for(int i = 1; i < int(a.size()); i++){
            p[i] = a[i].second;
            if(a[i - 1].first == a[i].first){
                c[a[i].second] = c[a[i - 1].second];
            }else{
                c[a[i].second] = c[a[i - 1].second] + 1;
            }
        }
        k++;
    }
    for(int i : p){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}