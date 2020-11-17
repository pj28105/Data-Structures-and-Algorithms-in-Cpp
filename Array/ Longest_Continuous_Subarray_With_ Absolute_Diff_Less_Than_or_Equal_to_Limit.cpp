#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

    Tested on Leetcdoe!

    Note-> This is o(n) solution to the problen with deques it can also be solved using heaps and segmanent tree!
    check leetcode submissions!
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int lim) {
        if(nums.empty()){
            return 0;
        }
        int n = nums.size(),s = 0,e = 1,ans = 1;
        deque<int>minq,maxq;
        minq.push_front(0);
        maxq.push_front(0);
        while(e < n){
            while(!minq.empty() && nums[minq.back()] > nums[e]){
                minq.pop_back();
            }
            while(!maxq.empty() && nums[maxq.back()] < nums[e]){
                maxq.pop_back();
            }
            minq.push_back(e);
            maxq.push_back(e);
            while((nums[maxq.front()] - nums[minq.front()]) > lim){
                s++;
                if(maxq.front() < s){
                    maxq.pop_front();
                }
                if(minq.front() < s){
                    minq.pop_front();
                }
            }
            ans = max(ans,e - s + 1);
            e++;
        }
        return ans;
    }
};