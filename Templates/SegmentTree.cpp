template<typename T>
class SegmentTree{
    /*
        To do-:
            1) Add merge logic.
            2) Set return value in query function in case of no overlap.
    */
    public:
        vector<T>tree;
        SegmentTree(int size){
            tree.resize((4 * size) + 5);
        }
        T merge(T left, T right){
            // Add Merge Logic Here
            return {};
        }
        void build(int s,int e,int si,vector<T> &arr){
            if(s == e){
                tree[si] = arr[s];
                return;
            }
            int mid = s + (e - s)/2;
            build(s,mid,2*si + 1,arr);
            build(mid + 1,e,2*si + 2,arr);
            tree[si] = merge(tree[2*si + 1],tree[2*si + 2]);
            return;
        }
        T query(int s,int e,int si,int l,int r){
            if(e < l || r < s){
                // Add some value
                return {};
            }
            if(l <= s && e <= r){
                return tree[si];
            }
            int mid = s + (e - s)/2;
            return merge(query(s,mid,2*si + 1,l,r),query(mid + 1,e,2*si + 2,l,r));
        }
        void update(int s,int e,int si,int index,T value){
            if(s == e){
                tree[si] = value;
                return;
            }
            int mid = s + (e - s)/2;
            if(index <= mid){
                update(s,mid,2*si + 1,index,value);
            }else{
                update(mid + 1,e,2*si + 2,index,value);
            }
            tree[si] = merge(tree[2*si + 1],tree[2*si + 2]);
            return;
        }
};