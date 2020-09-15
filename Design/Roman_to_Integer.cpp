#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2965/
    
    Tested on Leetcode!
*/
class Solution {
public:
    unordered_map<char,int>toInt;
    int romanToInt(string s) {
        if(toInt.empty()){
            toInt['I'] = 1;
            toInt['V'] = 5;
            toInt['X'] = 10;
            toInt['L'] = 50;
            toInt['C'] = 100;
            toInt['D'] = 500;
            toInt['M'] = 1000;
        }
        int ans = 0,prev = INT_MAX,curr = 0;
        for(int i = 0; i < s.length(); i++){
            curr = toInt[s[i]];
            if(prev < curr){
                ans -= prev;
                ans += (curr - prev);
            }else{
                ans += curr;
            }
            prev = curr;
        }
        return ans;
    }
};