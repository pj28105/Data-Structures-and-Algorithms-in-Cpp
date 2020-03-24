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
        unordered_map<char,Trie*> ch;
        bool isEnd;
        Trie(){
            this->isEnd = false;
        }
        void insert(string s){
            Trie *curr = this;
            for(int i = 0; i < s.length(); i++){
                s[i] = tolower(s[i]);
                if(curr->ch.find(s[i]) == curr->ch.end()){
                    curr->ch[s[i]] = new Trie();
                }
                curr = curr->ch[s[i]];
            }
            curr->isEnd = true; 
            return;
        }
        vector<string> query(string s){
            Trie* curr = this;
            vector<string> ans;
            for(int i = 0; i < s.length(); i++){
                if(curr->ch.find(s[i]) == curr->ch.end()){
                    ans.push_back("No suggestions");
                    return ans;
                }
                curr = curr->ch[s[i]];
            }
            this->dfs(curr,ans,s);
            return ans;
        }
        void dfs(Trie *root,vector<string>&ans,string s){
            if(root->isEnd){
                ans.push_back(s);
            }
            for(int i = 0; i <= 25; i++){
                if(root->ch.find(i + 'a') != root->ch.end())
                    dfs(root->ch[i + 'a'],ans,s + (char)(i + 'a'));
            }
            return;
        }
};

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
       freopen("../in.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    Trie *root = new Trie();
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        root->insert(s);
    }
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        vector<string> ans;
        ans = root->query(s);
        for(auto i : ans){
            cout << i << endl;
        }
        if(ans.size() > 0 && ans[0] == "No suggestions"){
            root->insert(s);
        }
    }
    return 0;
}