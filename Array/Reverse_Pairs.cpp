/*
    Problem link -> https://leetcode.com/problems/reverse-pairs
    Tested: True
    Time complexity -: O(NLogN)
    Space Complexity -: O(N)
    Note: Do check its another solution with binary index tree and compression
*/

class Solution {
public:
    
    int merge(vector<int>&nums, int start, int mid, int end){
        int currResult = 0, j = mid + 1, i = start;
        for( ; i <= mid; i++){
            while(j <= end && nums[i] > (2ll * nums[j])) {
                j++;
            }
            currResult += (j - (mid + 1));
        }
        i = start;
        j = mid + 1;
        vector<int> temp(end - start + 1);
        int tempIndex = 0;
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp[tempIndex++] = nums[i++];
            }else{
                temp[tempIndex++] = nums[j++];
            }
        }
        while(i <= mid){
            temp[tempIndex++] = nums[i++];
        }
        while(j <= end){
            temp[tempIndex++] = nums[j++];
        }
        for(i = start, tempIndex = 0; i <= end; tempIndex++,i++){
            nums[i] = temp[tempIndex];
        }
        return currResult;
    }
    
    int mergeSort(vector<int>&nums, int start, int end){
        if(start == end){
            return 0;
        }
        int mid = start + (end - start)/2;
        int result  = mergeSort(nums, start, mid);
        result += mergeSort(nums, mid + 1, end);
        result += merge(nums, start, mid, end);
        return result;
    }
    int reversePairs(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        return mergeSort(nums, 0, nums.size() - 1);
    }
};