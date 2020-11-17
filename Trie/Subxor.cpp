// https://www.spoj.com/problems/SUBXOR/
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
#define int long long

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
    Trie *left;
    Trie *right;
    int count;
    Trie(){
        this->count = 0;
        this->right = this->left = NULL;
    }
    void insert(int ele){
        Trie *curr = this;
        for(int i = 20; i >= 0; i--){
            int b = 1 & (ele >> i);
            if(b == 0){
                if(!curr->left){
                    curr->left = new Trie();
                }
                curr = curr->left;
                curr->count++;
            }else{
                if(!curr->right){
                    curr->right = new Trie();
                }
                curr = curr->right;
                curr->count++;
            }
        }
        return;
    }
    int query(int ele,int k){
        int currAns = 0;
        if(ele < k){
            currAns++;
        }
        Trie *curr = this;
        for(int i = 20; i >= 0; i--){
            if(!curr){
                break;
            }
            int b = (ele >> i) & 1;
            int bk = (k >> i) & 1;
            if(b == 0 && bk == 0){
                curr = curr->left;
            }else if(b == 0 && bk == 1){
                if(curr->left){
                    currAns += curr->left->count;
                }
                curr = curr->right;
            }else if(b == 1 && bk == 0){
                curr = curr->right;
            }else{
                if(curr->right){
                    currAns += curr->right->count;
                }
                curr = curr->left;
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
        int a[n],ans = 0,curr = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        Trie *root = new Trie();
        for(int i = 0; i < n; i++){
            curr = curr ^ a[i];
            ans += root->query(curr,k);
            root->insert(curr);
        }
        cout << ans << endl;
    }
    return 0;
}