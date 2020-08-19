#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

    Tested on Leetcdoe!

    Note-> Do chceck out its o(n) solution in arrays folder @github! 
    This is o(nlogn) solution to the problen with heaps it can also be solved using deques and segmanent tree!
    check leetcode submissions!
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int lim) {
        if(nums.empty()){
            return 0;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>max_heap;
        int min_index = 0,i = 1,ans = 1,n = nums.size();
        min_heap.push({nums[0],0});
        max_heap.push({nums[0],0});
        while(i < n){
            
            while(!min_heap.empty() && (abs(min_heap.top().first - nums[i]) > lim 
                                        || min_heap.top().second < min_index)){
                min_index = max(min_index,min_heap.top().second + 1);
                min_heap.pop();
            }
            
            while(!max_heap.empty() && (abs(max_heap.top().first - nums[i]) > lim 
                                        || max_heap.top().second < min_index)){
                min_index = max(min_index,max_heap.top().second + 1);
                max_heap.pop();
            }
            
            max_heap.push({nums[i],i});
            min_heap.push({nums[i],i});
            ans = max(ans,i - min_index + 1);
            i++;
        }
        return ans;
    }
};