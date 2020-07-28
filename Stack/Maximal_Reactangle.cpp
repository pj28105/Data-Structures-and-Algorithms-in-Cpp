#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://leetcode.com/problems/maximal-rectangle/
    
    Tested on Leetcode

    This problem is very similar to Largest Reactangle in Histogram!
*/
class Solution {
public:
    int solv(vector<int>&a){
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
    int maximalRectangle(vector<vector<char>>& a) {
        if(a.empty() || a[0].empty()){
            return 0;
        }
        int n = a.size(),m = a[0].size(),ans = 0;
        vector<int>hist(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == '1'){
                    hist[j]++;
                }else{
                    hist[j] = 0;
                }
            }
            ans = max(ans,solv(hist));
        }
        return ans;
    }
};