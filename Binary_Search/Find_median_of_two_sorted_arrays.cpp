#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/median-of-two-sorted-arrays/
    
    Corner Case:
        1) nums1.size() should always be less than or equal to nums2.size()

    Tested on Leetcode!
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        if(n == 0){
            if(m % 2 == 0){
                return (nums2[m/2] + nums2[m/2 - 1])/2.0;   
            }
            return nums2[m/2];
        }
        int l1 = 0, l2 = 0, r1 = 0, r2 = 0, st = 0, en = n;
        while(1) {
            int partition = (st + en) >> 1;
            int partition2 = (n + m + 1)/2 - partition;
            l1 = (partition == 0 ? INT_MIN : nums1[partition - 1]);
            r1 = (partition == n ? INT_MAX : nums1[partition]);
            l2 = (partition2 == 0 ? INT_MIN : nums2[partition2 - 1]);
            r2 = (partition2 == m ? INT_MAX : nums2[partition2]);
            if(l1 <= r2 && l2 <= r1){
                if((n + m) % 2 == 0){
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }else{
                    return max(l1, l2);
                }
            }else if(l1 > r2){
                en = partition - 1;
            }else{
                st = partition + 1;
            }
        }
        return -1.0;
    }
};