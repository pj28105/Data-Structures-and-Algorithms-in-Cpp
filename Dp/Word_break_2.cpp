#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://leetcode.com/problems/word-break-ii

    Backtracking optimize by dp.
*/

unordered_map<int,vector<string>>dp;
class Solution {
public:
    vector<string> solv(string s,unordered_set<string>&se,int in){
        if(in >= s.length()){
            return {""};
        }
        if(dp.find(in) != dp.end()){
            return dp[in];
        }
        string aux = "";
        vector<string> ans;
        for(int i = in; i < s.length(); i++){
            aux += s[i];
            if(se.find(aux) != se.end()){
                vector<string>temp = solv(s,se,i + 1);
                if(!temp.empty()){
                    for(string j : temp){
                        if(j.empty())
                            ans.push_back(aux);
                        else
                            ans.push_back(aux + " " + j);
                    }
                }
            }
        }
        dp[in] = ans;
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& dict) {
        dp.clear();
        unordered_set<string>se;
        for(string i : dict){
            se.insert(i);
        }
        vector<string> ans = solv(s,se,0);
        return ans;
    }
};