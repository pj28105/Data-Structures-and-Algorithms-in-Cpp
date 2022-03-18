/*
    Problem link -> https://leetcode.com/problems/reverse-pairs
    Tested: True
    Time complexity -: O(NLogN)
    Space Complexity -: O(N)
    Note: Do check its another solution with merge sort.
*/
class BinaryIndexTree{
  
    private:
        vector<int> tree;
        
    public:
        BinaryIndexTree(int size){
            tree.resize(size + 1, 0);
        }
        
        void updateValueInTree(int index, int value) {
            int treeSize = tree.size();
            while(index < treeSize) {
                tree[index] += value;
                index += index & (-index);
            }
        }
    
        int getPrefixSum(int index) {
            int prefixSum = 0;
            while(index > 0) {
                prefixSum += tree[index];
                index -= index & (-index);
            }
            return prefixSum;
        }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        map<long long, int> idToNumber;
        for(int i : nums){
            idToNumber[i] = 0;
            idToNumber[(2ll * i)] = 0;
        }
        int id = 1;
        for(auto it = idToNumber.begin(); it != idToNumber.end(); it++){
            idToNumber[it->first] = id;
            id++;
        }
        int result = 0, maxId = id - 1;
        BinaryIndexTree bit = BinaryIndexTree(maxId + 1);
        for(int i : nums) {
            int idForValue = idToNumber[i];
            int idForTwiceValue = idToNumber[2ll * i];
            result += bit.getPrefixSum(maxId) - bit.getPrefixSum(idForTwiceValue);
            bit.updateValueInTree(idForValue, 1);
        }
        return result;
    }
};