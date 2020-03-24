// PJ28105
// https://www.codechef.com/JUNE18B/problems/SHKSTR

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
        Trie(){
            this->isEnd = false;
        }
        void insert(string s){
            Trie *curr = this;
            for(int i = 0; i < s.length(); i++){
                if(curr->ch.find(s[i]) == curr->ch.end()){
                    curr->ch[s[i]] = new Trie();
                }
                curr = curr->ch[s[i]];
            }
            curr->isEnd = true;
            return;
        }
        string query(string s){
            Trie *curr = this;
            string ans = "";
            for(int i = 0; i < s.length(); i++){
                if(curr->ch.find(s[i]) == curr->ch.end()){
                    break;
                }
                curr = curr->ch[s[i]];
                ans += s[i];
            }
            ans = dfs(curr,ans);
            return ans;
        }
        string dfs(Trie *root,string ans){
            if(root->isEnd){
                return ans;
            }
            for(int i = 0; i < 26; i++){
                if(root->ch.find(i + 'a') != root->ch.end()){
                    return dfs(root->ch[i + 'a'],ans + (char)(i + 'a'));
                }
            }
            return "";
        }
    private:
        unordered_map<char,Trie*> ch;
        bool isEnd;
};

class Query{
    public:
        int in,r;
        string s;
        bool isQuery;
}q[200005];

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    int n,siz;
    cin >> n;
    for(siz = 0; siz < n; siz+=1){
        cin >> q[siz].s;
        q[siz].r = siz;
        q[siz].isQuery = false;
        q[siz].in = -1;
    }
    int qq;
    cin >> qq;
    for(int i = 0; i < qq; i++,siz++){
        cin >> q[siz].r >> q[siz].s;
        q[siz].r --;
        q[siz].isQuery = true;
        q[siz].in = i;
    }
    sort(q,q + siz,[](Query a,Query b)-> bool{
        if(a.r != b.r)
            return a.r < b.r;
        return a.in < b.in;
    });
    Trie *root = new Trie();
    vector<string> ans(qq);
    for(int i = 0; i < siz; i++){
       // deb(q[i].isQuery,q[i].in,q[i].r,q[i].s);
        if(q[i].isQuery){
            ans[q[i].in] = root->query(q[i].s);
        }else{
            root->insert(q[i].s);
        }
    }
    for(auto i: ans){
        cout << i << endl;
    }
    return 0;
}