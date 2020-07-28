#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/largest-rectangle-in-histogram/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        if(a.empty()){
            return 0;
        }
        stack<int> st;
        int i = 0,n = a.size();
        int ans = 0;
        while(i < n){
            if(st.empty() || a[st.top()] <= a[i]){
                st.push(i);
                i++;
            }else{
                int tp = st.top();
                st.pop();
                if(st.empty())
                    ans = max(ans,a[tp] * i);
                else
                    ans = max(ans,a[tp] * (i - st.top() - 1));
            }
        }
        while(!st.empty()){
            int tp = st.top();
            st.pop();
            if(st.empty()){
                ans = max(ans,a[tp] * i);
            }else{
                ans = max(ans,a[tp] * (i - st.top() - 1));
            }
        }
        return ans;
    }
};