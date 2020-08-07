#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/reorganize-string/
    
    Tested on Leetcode!
    Time-> o(Nlog(26))
    Space-> O(26)
*/
class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0},n = s.length();
        for(char c : s){
            freq[c - 'a']++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,less<pair<int,char>>>q;
        string ans = "";
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0)
                q.push({freq[i],i + 'a'});
        }
        while(q.size() > 1){
            char curr = q.top().second; q.pop();
            char nxt = q.top().second; q.pop();
            ans += curr;
            ans += nxt;
            freq[curr - 'a']--;
            freq[nxt - 'a']--;
            if(freq[curr - 'a'] > 0){
                q.push({freq[curr - 'a'],curr});
            }
            if(freq[nxt - 'a'] > 0){
                q.push({freq[nxt - 'a'],nxt});
            }
        }
        if(!q.empty()){
            char curr = q.top().second;
            if(freq[curr - 'a'] > 1){
                return "";
            }
            ans += curr;
        }
        return ans;
    }
};