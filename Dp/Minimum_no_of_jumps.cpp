#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://www.interviewbit.com/problems/min-jumps-array/
    
    Tested on Interview bit and leetocde!
*/
int jump(vector<int> &nums) {
    if(nums.size() == 1){
        return 0;
    }
    int st = 0;
    int ans = 0,n = nums.size();
    while(1){
        if((st + nums[st]) >= n - 1){
            return ans + 1;
        }
        ans++;
        int limit = st + nums[st],max_reach = 0,max_st = 0;
        for(int i = st + 1; i <= limit; i++){
            if(max_reach < (nums[i] + i)){
                max_reach = nums[i] + i;
                max_st = i;
            }
        }
        if(st >= max_st){
            return -1;
        }
        st = max_st;
    }
    return ans;      
}