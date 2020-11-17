/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/63/sorting-and-searching-4/3083/

    Tested on Leetcode!
    This problem can also be solved using BIT with compression check code in BIT folder!
*/
class Solution {
public:
    void merge(vector<int>&nums,int s,int mid,int e,vector<int>&ans,vector<int>&id){
        int i = s,j = mid + 1,in = 0,small = 0;
        int temp[e - s + 1],tempid[e - s + 1];
        while(i <= mid && j <= e){
            if(nums[i] > nums[j]){
                small++;
                temp[in] = nums[j];
                tempid[in++] = id[j];
                j++;
            }else{
                temp[in] = nums[i];
                tempid[in++] = id[i];
                ans[id[i]] += small;
                i++;
            }
        }
        while(i <= mid){
            temp[in] = nums[i];
            tempid[in++] = id[i];
            ans[id[i]] += small;
            i++;
        }
        while(j <= e){
            temp[in] = nums[j];
            tempid[in++] = id[j];
            j++;
        }
        for(int i = s,j = 0; i <= e; i++,j++){
            nums[i] = temp[j];
            id[i] = tempid[j];
        }
        return;
    }
    void mergeSort(vector<int>&nums,int s,int e,vector<int>&ans,vector<int>&id){
        if(s == e){
            return;
        }
        int mid = s + (e - s) /2;
        mergeSort(nums,s,mid,ans,id);
        mergeSort(nums,mid + 1,e,ans,id);
        merge(nums,s,mid,e,ans,id);
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty()){
            return {};
        }
        vector<int>id;
        for(int i = 0; i < nums.size(); i++){
            id.push_back(i);
        }
        vector<int>ans(nums.size());
        mergeSort(nums,0,nums.size() - 1,ans,id);
        return ans;
    }
};