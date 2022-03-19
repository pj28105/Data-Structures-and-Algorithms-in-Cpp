/*
    https://leetcode.com/problems/subarray-sum-equals-k/

    Tested: True
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, cnt = 0;
        unordered_map<int, int> prefixLookUp;
        prefixLookUp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(prefixLookUp.count(sum - k)){
                cnt += prefixLookUp[sum - k];
            }
            prefixLookUp[sum]++;
        }
        return cnt;
    }
};