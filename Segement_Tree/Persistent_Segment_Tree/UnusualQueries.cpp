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

/*

    Problem link->
        https://www.codechef.com/NOV20A/problems/UNSQUERS

    Tested on Codechef
*/

// Dirty Fix
// #define int long long

const int MAX = 1e5 + 500;

struct Node{
    Node* left,*right;
    int val,lazy;
    Node(int val = 0,int lazy = 0){
        this->right = this->left = NULL;
        this->val = val;
        this->lazy = lazy;
    }
    Node(Node* node){
        this->left = node->left;
        this->right = node->right;
        this->val = node->val;
        this->lazy = node->lazy; 
    }
}*root[MAX];

Node* build(int s,int e){
    if(s == e){
        return new Node(0);
    }
    Node* root = new Node(0);
    int mid = (s + e) >> 1;
    root->left = build(s,mid);
    root->right = build(mid + 1,e);
    return root;    
}

Node* update(Node* prev,int s,int e,int l,int r){
   if(e < l || r < s){
        return  prev;
    }
    Node* curr = new Node(prev);
    if(l <= s && e <= r){
        curr->lazy += 1;
        return curr;
    }
    int mid = s + (e - s)/2;
    curr->left = update(prev->left,s,mid,l,r);
    curr->right = update(prev->right,mid + 1,e,l,r);
    curr->val = max(curr->left->val + curr->left->lazy,
                    curr->right->val + curr->right->lazy);
    return curr;
}

int query(Node* curr,int s,int e,int l,int r){
    if(e < l || r < s){
        return INT_MIN;
    }
    if(l <= s && e <= r){
        return curr->val + curr->lazy;
    }
    int mid = (s + e) >> 1;
    return max(query(curr->left,s,mid,l,r),query(curr->right,mid + 1,e,l,r)) + curr->lazy;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int n,q,s;
    cin >> n >> q >> s;
    int h[n];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int updateTill[n];
    updateTill[0] = 0;
    stack<int>st;
    st.push(0);
    for(int i = 1; i < n; i++){
        while(!st.empty() && h[st.top()] < h[i]){
            st.pop();
        }
        if(st.empty()){
            updateTill[i] = 0;
        }else{
            updateTill[i] = st.top() + 1;
        }
        st.push(i);
    }
    // Build dummy segment tree
    root[0] = build(0,n - 1);

    for(int i = 1; i <= n; i++){
        root[i] = update(root[i - 1],0,n - 1,updateTill[i - 1],i - 1);
    }
    int lastans = 0,x,y,l,r;
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        l = (x + s*lastans - 1) % n;
        r = (y + s*lastans - 1) % n;
        if(l > r){
            swap(l,r);
        }
        lastans = query(root[r + 1],0,n - 1,l,r);
        cout << lastans << endl;
    }
    return 0;
}