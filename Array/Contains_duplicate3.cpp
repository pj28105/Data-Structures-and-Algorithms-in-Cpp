/*
    Problem link->
        https://leetcode.com/problems/contains-duplicate-iii/
    
    This is O(n) solution to this problem by dividing numbers in bucket checkout its O(nlogn) solution
    in greedy folder.

    Tested on Leetcode!
*/
class Solution {
public:
    long getBucketID(long n,long size){
        if(n >= 0){
            return (n/size);
        }
        return ((n + 1)/size) - 1;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0){
            return 0;
        }
        unordered_map<long,long>buckets;
        long buckSize = t + 1l;
        for(int i = 0; i < nums.size(); i++){
            long buckId = getBucketID(nums[i],buckSize);
            if(buckets.count(buckId)){
                return 1;
            }
            buckets[buckId] = nums[i];
            if(buckets.count(buckId - 1) && abs(buckets[buckId - 1] - nums[i]) <= t){
                return 1;
            }
            if(buckets.count(buckId + 1) && abs(buckets[buckId + 1] - nums[i]) <= t){
                return 1;
            }
            if(buckets.size() > k){
                buckId = getBucketID(nums[i - k],buckSize);
                buckets.erase(buckId);
            }
        }
        return 0;
    }
};