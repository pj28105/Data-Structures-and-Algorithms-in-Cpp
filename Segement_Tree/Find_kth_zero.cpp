#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 100;
int seg[4*MAX];

void build(int a[],int s,int e,int si){
    if(s == e){
        seg[si] = a[s] == 0 ? 1 : 0;
        return;
    }
    int mid = (s + e) >> 1;
    build(a,s,mid,2*si + 1);
    build(a,mid + 1,e,2*si + 2);
    seg[si] = seg[2*si + 1] + seg[2*si + 2];
}

void update(int s,int e,int si,int ele,int in){
    if(s == e){
        seg[si] = ele == 0 ? 1 : 0;
        return;
    }
    int mid = (s + e) >> 1;
    if(in <= mid){
        update(s,mid,2*si + 1,ele,in);
    }else{
        update(mid + 1,e,2*si + 2,ele,in);
    }
    seg[si] = seg[2*si + 1] + seg[2*si + 2];
    return;
}

int query(int s,int e,int si,int k){
    if(s == e){
        return s;
    }
    int mid = (s + e) >> 1;
    if(seg[2*si + 1] >= k){
        return query(s,mid,2*si + 1,k);
    }
    return query(mid + 1,e,2*si + 2,k - seg[2*si + 1]);
}

int main() {
    int n,q;
    cin >> n >> q;
    int a[n];
    int zc = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(!a[i])
            zc++;
    }
    build(a,0,n - 1,0);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int k;
            cin >> k;
            if(k > zc){
                cout << "NO" << endl;
            }else{
                cout << query(0,n - 1,0,k) << endl;
            }
        }else{
            int in,ele;
            cin >> in >> ele;
            if(a[in] == 0 && ele != 0){
                zc--;
            }else if(a[in] != 0 && ele == 0){
                zc++;
            }
            a[in] = ele;
            update(0,n - 1,0,ele,in);
        }
    }
    return 0;
}