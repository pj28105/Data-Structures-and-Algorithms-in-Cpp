/*
    Problem link->
        https://leetcode.com/problems/single-number-ii/
    
    Tested on Leetcode!

    This code suprisingly works for negative numbers too!
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32] = {0};
        int n = nums.size();
        for(int i = 0; i < 32; i++){
            long long mask = 1ll << i;
            for(int j = 0; j < n; j++){
                if(mask & nums[j]){
                    bit[i]++;
                }
            }
        }
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            if(bit[i] % 3){
                long long mask = 1ll << i;
                ans += mask;
                cout << ans << endl;
             }
        }
        return ans;
    }
};