#include<bits/stdc++.h>
using namespace std;

/*
    Problem link link->
        https://leetcode.com/problems/word-ladder/

    Checout more optimized solution on leetcode!

    Note-> This problem in from Amazon sde test serise. GFG has wrong testcases for this problem.
        Don't look at the GFG editoral too.

    Tested on Leetcode
*/

class Solution {
public:
    int ladderLength(string s, string d, vector<string>& dict) {
        if(s == d){
            return 0;
        }
        dict.push_back(s);
        unordered_map<string,vector<string>>g;
        for(int i = 0; i < dict.size(); i++){
            for(int j = i + 1; j < dict.size(); j++){
                int ch = 0;
                for(int k = 0; k < dict[i].length(); k++){
                    if(dict[i][k] != dict[j][k]){
                        ch++;
                    }
                    if(ch >= 2){
                        break;
                    }
                }
                if(ch <= 1){
                    g[dict[i]].push_back(dict[j]);
                    g[dict[j]].push_back(dict[i]);
                }
            }
        }
        unordered_set<string>vis;
        int ans = 0;
        queue<string> q;
        q.push(s);
        vis.insert(s);
        while(!q.empty()){
            ans++;
            int n = q.size();
            while(n--){
                string curr = q.front();
                if(curr == d){
                    return ans;
                }
                q.pop();
                for(string i : g[curr]){
                    if(vis.find(i) == vis.end()){
                        q.push(i);
                        vis.insert(i);
                    }
                }
            }
        }
        return 0;   
    }
};