#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/median-of-two-sorted-arrays/
    
    Tested on Leetcode!
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n = nums1.size(),m = nums2.size();
        if(n == 0){
            if(m & 1){
                return nums2[m/2];
            }
            return (nums2[m/2] + nums2[m/2 - 1])/2.0;
        }
        int s = 0,e = n,min_x,max_x,min_y,max_y,mid,ypart;
        while(1){
            mid = s + (e - s)/2;
            ypart = (n + m + 1)/2 - mid;
            min_x = mid == 0 ? INT_MIN : nums1[mid - 1];
            max_x = mid == n ? INT_MAX : nums1[mid];
            min_y = ypart == 0 ? INT_MIN : nums2[ypart - 1];
            max_y = ypart == m ? INT_MAX : nums2[ypart];
            if(min_x <= max_y && min_y <= max_x){
                if((n + m) & 1){
                    return max(min_x,min_y);
                }
                return (max(min_x,min_y) + min(max_x,max_y))/2.0;
            }
            else if(min_x > max_y){
                e = mid - 1;
            }else{
               s = mid + 1; 
            }
        }
        return -1;
    }
};