#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
    This is implementation of segment tree.
    It is tested on Spoj!

    Problem link->
        https://www.spoj.com/problems/CSUMQ/
*/
ll seg[4*100001];

void build(ll a[],int s,int e,int si){
    if(s == e){
        seg[si] = a[s];
        return;
    }
    int mid = s + (e - s)/2;
    build(a,s,mid,2*si + 1);
    build(a,mid + 1,e,2*si + 2);
    seg[si] = seg[2*si + 1] + seg[2*si + 2];
    return;
}

ll query(int s,int e,int si,int l,int r){
    if(e < l || r < s){
        return 0;
    }
    if(l <= s && e <= r){
        return seg[si];
    }
    int mid = s + (e - s)/2;
    return query(s,mid,2*si + 1,l,r) + query(mid + 1,e,2*si + 2,l,r);
}

int main(void){
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(a,0,n - 1,0);
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << query(0,n - 1,0,l,r) << endl;
    }
}