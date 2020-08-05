/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/63/sorting-and-searching-4/3083/
    
    Tested on Leetcode!
    This problem can be solved using merge sort check Trees/Advance folder on github! 
*/
class Solution {
public:
    void update(int i,int *bit,int id){
        while(i < id){
            bit[i]++;
            i += i & (-i);
        }
        return;
    }
    int query(int i,int *bit){
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
        map<int,int> ma;
        for(int i : nums){
            ma[i] = 0;
        }
        int id = 1;
        for(auto i : ma){
            ma[i.first] = id;
            id++;
        }
        int *bit = new int[id];
        memset(bit,0,sizeof(int) * id);
        int n = nums.size();
        vector<int>ans(n);
        for(int i = n - 1; i >= 0; i--){
            ans[i] = query(ma[nums[i]] - 1,bit);
            update(ma[nums[i]],bit,id);
        }
        return ans;
    }
};