#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/maximum-product-subarray/

    Tested on Leetcode!
*/
class Solution
{
public:
    int maxProduct(vector<int> &nums){
        int max_prod = nums[0],min_prod = nums[0],ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(min_prod,max_prod);
            }
            max_prod = max(max_prod * nums[i],nums[i]);
            min_prod = min(min_prod * nums[i],nums[i]);
            ans = max(ans,max_prod);
        }
        return ans;
    }
};