template<typename T>
class BIT{
    /*
        Warning!
            1) Query function return type is long long , adjust it as per use. 
            2) Default update operation is add.
            3) Binary Index Tree works on 1 based indexing.
    */
    public:
        int size;
        vector<T> tree;
        BIT(int size){
            this->size = size;
            tree.resize(size + 1);
        }
        void update(int index,T val){
            while(index <= size){
                tree[index] += val;
                index += (index & (-index));
            }
        }
        long long query(int index){
            long long sum = 0;
            while(index > 0){
                sum += tree[index];
                index -= (index & (-index));
            }
            return sum;
        }
};