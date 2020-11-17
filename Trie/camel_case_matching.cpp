// PJ28105
// https://practice.geeksforgeeks.org/problems/camelcase-pattern-matching/0

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
        vector<string>st;
        bool isEnd;
        unordered_map<char,Trie*>ch;
        Trie(){
            this->isEnd = false;
        }
        void insert(string s){
            Trie *curr = this;
            for(char c : s){
                if(c >= 'a' && c <= 'z'){
                    continue;
                }
                if(curr->ch.find(c) == curr->ch.end()){
                    curr->ch[c] = new Trie();
                }
                curr = curr->ch[c];
            }
            curr->isEnd = true;
            curr->st.push_back(s);
            return;
        }

        void dfs(Trie *root){
            if(root->isEnd){
                for(auto i : root->st){
                    cout << i << " ";
                }
            }
            for(int i = 0; i < 26; i++){
                if(root->ch.find(i + 'A') != root->ch.end()){
                    dfs(root->ch[i + 'A']);
                }
            }
            return;
        }

        bool match(string s){
            Trie *root = this;
            for(int i = 0; i < s.length(); i++){
                if(root->ch.find(s[i]) == root->ch.end()){
                    return false;
                }
                root = root->ch[s[i]];
            }
            this->dfs(root);
            return true;
        }
};

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
      freopen("../in.txt","r",stdin);
    #endif
    tc{
        int n;
        cin >> n;
        vector<string>v(n);
        Trie *root = new Trie();
        for(int i = 0; i < n; i++){
            cin >> v[i];
            root->insert(v[i]);
        }
        string s;
        cin >> s;
        if(!root->match(s)){
            cout << "No match found";
        }
        cout << endl;
    }
    return 0;
}