#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/multiply-strings/
    
    Tested on Leetcode!
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        string ans(num1.size() + num2.size(),'0');
        for(int i = num1.length() - 1; i >= 0; i--){
            int carry = 0;
            for(int j = num2.length() - 1; j >= 0; j--){
                int prod = (ans[i + j + 1] - '0') + (num2[j] - '0') * (num1[i] - '0') + carry;
                ans[i + j + 1] = (prod % 10) + '0';
                carry = prod/10;
            }
            ans[i] = carry + '0';
        }
        int in = -1;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] != '0'){
                in = i;
                break;
            }
        }
        return in == -1 ? "0" : ans.substr(in);
    }
};