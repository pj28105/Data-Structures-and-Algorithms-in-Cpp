#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/59/array-and-strings/3047/

    Tested on Leetcode!

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        unordered_map<char,int> lastFound;
        int ans = 0,i = 0,j = 0;
        while(i < s.length()){
            if(lastFound.find(s[i]) != lastFound.end()){
                j = max(lastFound[s[i]] + 1,j);
            }
            lastFound[s[i]] = i;
            ans = max(ans,i - j + 1);
            i++;
        }
        return ans;
    }
};