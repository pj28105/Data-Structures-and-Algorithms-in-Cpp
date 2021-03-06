//PJ28105

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

class Trie{
    public:
        unordered_map<char ,Trie*> ch;
        int count;
        Trie(){
            this->count = 0;
        }
        void insert(string s){
            Trie *curr = this;
            for(int i = 0; i < s.length(); i++){
                if(curr->ch.find(s[i]) == curr->ch.end()){
                    curr->ch[s[i]] = new Trie();
                }
                curr = curr->ch[s[i]];
                curr->count++;
            }
        }
        int dfs(int k,Trie *root){
            Trie *curr = root;
            int currAns = curr->count/k;;
            for(int i = 0; i < 26; i++){
                if(curr->ch.find(i + 'A') != curr->ch.end()){
                    currAns += dfs(k,curr->ch[i + 'A']);
                }
            }
            return currAns;
        }
};

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    tc{
        int n,k;
        cin >> n >> k;
        Trie * root = new Trie();
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            root->insert(s);
        }
        cout << "Case #" << tt << ": " << root->dfs(k,root) << endl; 
    }
    return 0;
}