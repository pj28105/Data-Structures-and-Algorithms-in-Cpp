class DSU{
    /*
        Note :
            1) union_them() function returns true if components are different otherwise it returns false.
            2) This DSU implementation is based on union by rank and path compression.
    */
    public:
        int size;
        vector<int>parent,rank;
        DSU(int size){
            parent.resize(size);
            rank.resize(size);
            fill(rank.begin(),rank.end(),0);
            iota(parent.begin(),parent.end(), 0); 
        }
        int find(int curr){
            if(parent[curr] == curr){
                return curr;
            }
            parent[curr] = find(parent[curr]);
            return parent[curr];
        }
        bool union_them(int x,int y){
            int parentX = find(x);
            int parentY = find(y);
            if(parentX == parentY){
                return false;
            }
            if(rank[parentX] > rank[parentY]){
                parent[parentY] = parentX;
            }else if(rank[parentY] > rank[parentX]){
                parent[parentX] = parentY;
            }else{
                parent[parentX] = parentY;
                rank[parentY]++;
            }
            return true;
        }
};