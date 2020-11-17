// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/description/
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

class Trie{
    public:
        unordered_map<char,Trie*> ch;
        int w;
        Trie(){
            this->w = -1;
        }
};

void insert(string s,Trie *root,int we){
    for(int i = 0; i < s.length(); i++){
        if(root->ch.find(s[i]) == root->ch.end()){
            root->ch[s[i]] = new Trie();
        }
        root = root->ch[s[i]];
        root->w = max(root->w,we);
    }
    return;
}

int query(Trie *root,string s){
    for(int i = 0; i < s.length(); i++){
        if(root->ch.find(s[i]) == root->ch.end()){
            return -1;
        }
        root = root->ch[s[i]];
    }
    return root->w;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    int n,q;
    cin >> n >> q; 
    Trie *root = new Trie();
    for(int i = 0; i < n; i++){
        string s;
        int we;
        cin >> s >> we;
        insert(s,root,we);
    }
    while(q--){
        string s;
        cin >> s;
        int ans = query(root,s);
        cout << ans << endl;
    }
    return 0;
}