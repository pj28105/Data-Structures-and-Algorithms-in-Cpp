/*
    Problem link->
        https://leetcode.com/problems/trapping-rain-water/

    Tested on Leetcode!
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        stack<int>st;
        int i = 0,ans = 0;
        while(i < height.size()){
            if(!st.empty() && height[i] > height[st.top()]){
                int tp = st.top();
                st.pop();
                if(st.empty()){
                    continue;
                }
                int width = i - st.top() - 1;
                int h = min(height[st.top()],height[i]) - height[tp];
                ans += h * width;
                
            }else{
                st.push(i);
                i++;
            }
        }
        return ans;
    }
};