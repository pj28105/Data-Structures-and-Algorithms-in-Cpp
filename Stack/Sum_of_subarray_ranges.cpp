/*
    Problem link-> https://leetcode.com/problems/sum-of-subarray-ranges/

    Tested on leetcode!

    Most recently asked Amazon Question!
*/
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        long ans = 0;
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] <= nums[i])) {
                int curr = st.top();
                st.pop();
                int rightCnt = i - 1 - curr;
                int leftCnt = curr - (st.empty() ? 0 : st.top() + 1);
                ans += nums[curr] * (1ll + rightCnt * leftCnt + rightCnt + leftCnt);   
            }
            st.push(i);
        }
        st.pop();
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])) {
                int curr = st.top();
                st.pop();
                int rightCnt = i - 1 - curr;
                int leftCnt = curr - (st.empty() ? 0 : st.top() + 1);
                ans -= nums[curr] * (1ll + rightCnt * leftCnt + rightCnt + leftCnt);   
            }
            st.push(i);
        }
        return ans;
    }
};