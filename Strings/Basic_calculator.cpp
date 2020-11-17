#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/basic-calculator/
    Tested on Leetcode!
*/
class Solution {
public:
    int calculate(string s) {
        stack<string>st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int num = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                if(!st.empty() && (st.top() == "+" || st.top() == "-")){
                    if(st.top() == "-"){
                        num *= -1;
                    }
                    st.pop();
                }
                st.push(to_string(num));
            }else if(s[i] == '(' || s[i] == '+' || s[i] == '-'){
                st.push(string(1,s[i]));
            }else if(s[i] == ')'){
                int sum = 0;
                while(st.top() != "("){
                    sum += stoi(st.top());
                    st.pop();
                }
                st.pop();
                if(!st.empty() && (st.top() == "+" || st.top() == "-")){
                    if(st.top() == "-"){
                        sum *= -1;
                    }
                    st.pop();
                }
                st.push(to_string(sum));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += stoi(st.top());
            st.pop();
        }
        return ans;
    }
};