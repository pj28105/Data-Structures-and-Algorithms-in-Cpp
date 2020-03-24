// PJ28105
// MARK 2

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
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define deb(...)
#endif

class Node{
    public:
        Node *left;
        Node *right;
};

// Zero -> left
// One -> right

void insert(int ele,Node *root){
    for(int i = 31; i >= 0; i--){
        ll b = (1ll << i) & ele;
        if(b > 0){
            if(!root->right){
                root->right = new Node();
            }
            root = root->right;
        }else{
             if(!root->left){
                root->left = new Node();
            }
            root = root->left;
        }
    }
    return;
}

ll query(int ele,Node* root){
    ll currAns = 0;
    for(int i = 31; i >= 0; i--){
        ll b = (1ll << i) & ele;
        if(b > 0){
            if(root->left){
                currAns = currAns | (1ll << i);
                root = root->left;
            }else{
                root = root->right;
            }
        }else{
            if(root->right){
                currAns = currAns | (1ll << i);
                root = root->right;
            }else{
                root = root->left;
            }
        }
    }
    return currAns;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    int a[n];
    ll ans = 0;
    Node *root = new Node();
    for(int i = 0; i < n; i++){
        cin >> a[i];
        insert(a[i],root);
        ans = max(query(a[i],root),ans);
    }
    cout << ans << endl;
    return 0;
}