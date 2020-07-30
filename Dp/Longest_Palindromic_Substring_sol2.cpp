#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/451/
    
    Tested on Leetcode!
*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if(s.empty()){
            return "";
        }
        int st = 0,maxLen = 1;
        for(int i = 0; i < s.length(); i++){
            int l = i,r = i + 1,len = 0;
            while(l >= 0 && r < s.length()){
                if(s[l] == s[r]){
                    len += 2;
                }else{
                    break;
                }
                l--,r++;
            }
            if(len > maxLen){
                maxLen = len;
                st = l + 1;
            }
            len = 1,l = i - 1,r = i + 1;
            while(l >= 0 && r < s.length()){
                if(s[l] == s[r]){
                    len += 2;
                }else{
                    break;
                }
                l--,r++;
            }
            if(len > maxLen){
                maxLen = len;
                st = l + 1;
            }
        }
        return s.substr(st,maxLen);
    }
};