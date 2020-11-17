struct SegmentTree{
    vector<ll> tree;
    SegmentTree(int n){
        tree.assign(4*n,0);
    }
    void build(int a[],int s,int e,int si){
        if(s == e){
            tree[si] = a[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(a,s,mid,2*si + 1);
        build(a,mid + 1,e,2*si + 2);
        tree[si] = tree[2*si + 1] + tree[2*si + 2];
        return;
    }
    ll query(int s,int e,int si,int l,int r){
        if(r < s || e < l){
            return 0;
        }
        if(l <= s && e <= r){
            return tree[si];
        }
        int mid = (s + e) >> 1;
        ll ans = query(s,mid,2*si + 1,l,r);
        ans += query(mid + 1,e,2*si + 2,l,r);
        return ans; 
    }
    void update(int s,int e,int si,int in,int val){
        if(s == e){
            tree[si] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if(in <= mid){
            update(s,mid,2*si + 1,in,val);
        }else{
            update(mid + 1,e,2*si + 2,in,val);
        }
        tree[si] = tree[2*si + 1] + tree[2*si + 2];
        return;
    }
};