#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/candy/
    
    Tested on Leetcde
*/

class Solution {
public:
    int candy(vector<int>& a) {
        vector<int> ans(a.size(),0);
        ans[0] = 1;
        for(int i = 1; i < a.size(); i++){
            if(a[i] > a[i - 1]){
                ans[i] = ans[i - 1] + 1;
            }else
                ans[i] = 1;
        }
        int sum = ans.back();
        for(int i = a.size() - 2; i >= 0; i--){
            if(a[i] > a[i + 1]){
                ans[i] = max(ans[i + 1] + 1,ans[i]);
            }
            sum += ans[i];
        }
        return sum;
    }
};