/*

    Problem link->
        https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
    
    Tested on Leetcode!

    This problem can also be solved by reversing the array!
    This solution is based on juggling algotihm!
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int siz = nums.size();
        k = k % siz;
        if(k == 0){
            return;
        }
        int cnt = 0;
        for(int i = 0; cnt < nums.size(); i++){
            int currIndex = i;
            int prev = nums[i];
            do{
                int nextIndex = (currIndex + k) % siz;
                int temp = nums[nextIndex];
                nums[nextIndex] = prev;
                prev = temp;
                currIndex = nextIndex;
                cnt++;
            }while(currIndex != i);
        }
        return;
    }
};