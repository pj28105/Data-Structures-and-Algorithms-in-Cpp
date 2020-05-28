#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll seg[4*100002],lazy[4*100002];

void update(int s,int e,int si,int l,int r,ll val){
    if(lazy[si] != 0){
        seg[si] += ((e - s + 1) * lazy[si]);
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
        seg[si] += (e - s + 1)*val;
        if(s != e){
            lazy[2*si + 1] += val;
            lazy[2*si + 2] += val;
        }
        return;
    }
    int mid = s + (e - s)/2;
    update(s,mid,2*si + 1,l,r,val);
    update(mid + 1,e,2*si + 2,l,r,val);
    seg[si] = seg[2*si + 1] + seg[2*si + 2];
    return;
}

ll query(int s,int e,int si,int l,int r){
    if(lazy[si] != 0){
        seg[si] += ((e - s + 1) * lazy[si]);
        if(s != e){
            lazy[2*si + 1] += lazy[si];
            lazy[2*si + 2] += lazy[si];
        }
        lazy[si] = 0;
    }

    if(e < l || s > r){
        return 0ll;
    }
    
    if(l <= s && e <= r){
        return seg[si];
    }
    int mid = s + (e - s)/2;
    ll sum =  query(s,mid,2*si + 1,l,r) + query(mid + 1,e,2*si + 2,l,r);
    return sum;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        while(q--){
            int type,l,r;
            cin >> type;
            if(type == 0){
                ll val;
                cin >> l >> r >> val;
                l--,r--;
                update(0,n - 1,0,l,r,val);
            }else{
                cin >> l >> r;
                l--,r--;
                cout << query(0,n - 1,0,l,r) << endl;
            }
        }
        memset(seg,0,sizeof(seg));
        memset(lazy,0,sizeof(lazy));
    }   
}