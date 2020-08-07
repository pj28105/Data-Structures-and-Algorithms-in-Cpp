#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/rearrange-string-k-distance-apart/

    Tested on Leetcode!

    This is a follow up question for reorganize string!
*/
class Solution {
public:
    string rearrangeString(string s, int k) {
        if(s.empty() || k == 0){
            return s;
        }
        int freq[26] = {0};
        for(char c : s){
            freq[c - 'a']++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,less<pair<int,char>>>q;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0)
                q.push({freq[i],i + 'a'});
        }
        string ans = "";
        vector<char>curr;
        while(q.size() >= k){
            for(int i = 0; i < k; i++){
                curr.push_back(q.top().second);
                ans += curr.back();
                q.pop();
            }
            for(int i = curr.size() - 1; i >= 0; i--){
                freq[curr[i] - 'a']--;
                if(freq[curr[i] - 'a'] > 0){
                    q.push({freq[curr[i] - 'a'],curr[i]});
                }
                curr.pop_back();
            }
        }
        while(!q.empty()){
            char curr = q.top().second;
            if(freq[curr - 'a'] > 1){
                return "";
            }else{
                ans += curr;
            }
            q.pop();
        }
        return ans;
    }
};