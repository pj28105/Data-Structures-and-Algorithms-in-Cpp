/*
    Problem link->
        https://leetcode.com/problems/split-array-into-consecutive-subsequences/
    
    Tested on Leetcode!
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>ma,end;
        for(int i = 0; i < nums.size(); i++){
            ma[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(ma[nums[i]] > 0){
                ma[nums[i]]--;
                if(end[nums[i] - 1] > 0){
                    end[nums[i] - 1]--;
                    end[nums[i]]++;
                }
                else if(ma[nums[i] + 1] > 0 && ma[nums[i] + 2] > 0){
                    ma[nums[i] + 1]--;
                    ma[nums[i] + 2]--;
                    end[nums[i] + 2]++;
                }else{
                    return 0;
                }
            }
        }
        return 1;
    }
};