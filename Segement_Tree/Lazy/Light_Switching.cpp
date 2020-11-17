#include<bits/stdc++.h>
using namespace std;

struct tree{
    int off,on;
}seg[4*100005];

int lazy[4*100005];

void build(int s,int e,int si){
    if(s == e){
        seg[si].off = 1;
        seg[si].on = 0;
        return;
    }
    int mid = s + (e - s)/2;
    build(s,mid,2*si + 1);
    build(mid + 1,e,2*si + 2);
    seg[si].off = seg[2*si + 1].off + seg[2*si + 2].off;
    seg[si].on = seg[2*si + 1].on + seg[2*si + 2].on;
    return;
}

void update(int s,int e,int si,int l,int r){
    lazy[si] = lazy[si] % 2;
    if(lazy[si] != 0){
        swap(seg[si].off,seg[si].on);
        if(s != e){
            lazy[2*si + 1] += lazy[si];
            lazy[2*si + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if(e < l || r < s){
        return;
    }
    if(l <= s && e <= r){
        swap(seg[si].off,seg[si].on);
        if(s != e){
            lazy[2*si + 1] += 1;
            lazy[2*si + 2] += 1;
        }
        return;
    }
    int mid = s + (e - s)/2;
    update(s,mid,2*si + 1,l,r);
    update(mid + 1,e,2*si + 2,l,r);
    seg[si].off = seg[2*si + 1].off + seg[2*si + 2].off;
    seg[si].on = seg[2*si + 1].on + seg[2*si + 2].on;
    return;
}

int query(int s,int e,int si,int l,int r){
    lazy[si] = lazy[si] % 2;
    if(lazy[si] != 0){
        swap(seg[si].off,seg[si].on);
        if(s != e){
            lazy[2*si + 1] += lazy[si];
            lazy[2*si + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if(e < l || r < s){
        return 0;
    }
    if(l <= s && e <= r){
        return seg[si].on;
    }
    int mid = s + (e - s)/2;
    int sum = query(s,mid,2*si + 1,l,r);
    sum += query(mid + 1,e,2*si + 2,l,r);
    return sum;
}

int main(void){
    int n,q;
    cin >> n >> q;
    build(0,n - 1,0);
    while(q--){
        int type,l,r;
        cin >> type >> l >> r;
        l--,r--;
        if(!type){
            update(0,n - 1,0,l,r);
        }else{
            cout << query(0,n - 1,0,l,r) << endl;
        }
    }
}