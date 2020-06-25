/*
    Problem link->
        https://leetcode.com/problems/find-the-duplicate-number/
    

    Tested on Leetcode!
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            
        }while(slow != fast);
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};