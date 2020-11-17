/*
    Problem link->
        https://leetcode.com/problems/contains-duplicate-iii/
    
    This is O(nlogn) solution using map checkout its O(n) solution in Array folder.
    Tested on Leetcode!

    This code can be simplified further checout disscusions on leetcode!
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty() || k <= 0){
            return 0;
        }
        map<long,long>ma;
        int i = 1,j = 0,n = nums.size();
        while(i < n){
            ma[nums[i]]++;
            if((i - j) <= k){
                auto it = ma.lower_bound(long(nums[j]) - t);
                if(it != ma.end() && it->first <= (long(nums[j]) + t)){
                    return 1;
                }
                if((i - j) == k){
                    j++;
                    ma[nums[j]]--;
                    if(ma[nums[j]] == 0){
                        ma.erase(nums[j]);
                    }   
                }
            }
            i++;
        }
        for(; j < n; j++){
            auto it = ma.lower_bound(long(nums[j]) - t);
            if(it != ma.end() && it->first <= (long(nums[j]) + t)){
                return 1;
            }
            if((j + 1) < n){
                ma[nums[j + 1]]--;
                if(ma[nums[j + 1]] == 0){
                    ma.erase(nums[j + 1]);
                }
            }
        }
        return 0;
    }
};