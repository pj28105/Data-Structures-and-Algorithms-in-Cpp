#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/remove-k-digits/
    Tested on Leetcode!
*/
class Solution {
public:
    string removeKdigits(string s, int k) {
        if(k == 0){
            return s;
        }
        if(s.length() == k){
            return "0";
        }
        int req = s.length() - k,len = 0;
        vector<char>st;
        int i = 0;
        while(i < s.length() && k > 0){
            while(k > 0 && !st.empty() && s[i] < st.back()){
                st.pop_back();
                k--;
            }
            if(s[i] != '0'){
                st.push_back(s[i]);
            }else if(s[i] == '0' && !st.empty()){
                st.push_back(s[i]);
            }
            i++;
        }
        string ans = "";
        for(int j = 0;  len < req && j < st.size(); j++,len++){
            ans += st[j];
        }
        for(; i < s.length() && len < req; i++,len++){
            ans += s[i];
        }
        return len == 0 ? "0" : ans;
    }
};