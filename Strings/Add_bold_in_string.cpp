#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/add-bold-tag-in-string/

    Tested on Leetcode!

    This problem is solved with boundary prefix sum trick!
*/
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int bound[s.length() + 1];
        memset(bound,0,sizeof(bound));
        unordered_set<string>se(dict.begin(),dict.end());
        for(int i = 0; i < s.length(); i++){
            string sub = "";
            for(int j = i; j < s.length(); j++){
                sub += s[j];
                if(se.count(sub)){
                    bound[i]++;
                    bound[j + 1]--;
                }
            }
        }
        string ans = "";
        for(int i = 0; i <= s.length(); i++){
            if(bound[i] > 0){
                int sum = bound[i],st = i;
                i++;
                while(i <= s.length() && sum > 0){
                    sum += bound[i];
                    i++;
                }
                i--;
                ans = ans + "<b>" + s.substr(st,i - st) + "</b>";
                if(i < s.length()){
                    ans += s[i];
                }
            }else if(i < s.length()){
                ans += s[i];
            }
        }
        return ans;    
    }
};

