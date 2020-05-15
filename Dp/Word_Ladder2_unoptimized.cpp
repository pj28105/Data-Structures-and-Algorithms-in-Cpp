#include<bits/stdc++.h>
using namespace std;
/*

    Problem link->
        https://leetcode.com/problems/word-ladder-ii/

      1) This Solution is not much optimize and it is harder to implement as it requires (BFS,DFS,DP)
     See optimized solution on github . Source of solution is from interviewbit
     https://www.interviewbit.com/problems/word-ladder-ii/

     Tested on Leetcode
*/

map<pair<int,string>,vector<vector<string>>>dp; 
class Solution {
public:
    int path_len;
    string dest;
    int bfs(string& s,string& d,unordered_map<string,unordered_set<string>>&g){
        unordered_set<string>vis;
        queue<string>q;
        q.push(s);
        int movs = 0;
        while(!q.empty()){
            movs++;
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == d){
                    return movs;
                }
                for(string s : g[curr]){
                    if(vis.find(s) == vis.end()){
                        q.push(s);
                        vis.insert(s);
                    }
                }
            }
        }
        return 0;
    }
    vector<vector<string>> dfs(int len,unordered_set<string>&vis,unordered_map<string,unordered_set<string>>&g,string& s){
        if(len == path_len && s == dest){
            return {{ dest }};
        }
        if(path_len <= len){
            return {};
        }
        if(dp.find({len,s}) != dp.end()){
            return dp[{len,s}];
        }
        vis.insert(s);
        vector<vector<string>> currAns;
        for(string i : g[s]){
            if(vis.find(i) == vis.end()){
                vector<vector<string>> poss = dfs(len + 1,vis,g,i);
                for(auto j : poss){
                    j.push_back(s);
                    currAns.push_back(j);
                }
            }
        }
        dp[{len,s}] = currAns;
        vis.erase(s);
        return currAns;
    }
    vector<vector<string>> findLadders(string s, string d, vector<string>& dict) {
        dp.clear();
        unordered_map<string,unordered_set<string>>g;
        dict.push_back(s);
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
                    g[dict[i]].insert(dict[j]);
                    g[dict[j]].insert(dict[i]);
                }
            }
        }
        path_len = bfs(s,d,g);
        if(path_len == 0){
            return {};
        }
        dest = s;
        vector<vector<string>>ans;
        unordered_set<string>vis;
        vector<vector<string>> inter = dfs(1,vis,g,d);
        for(auto &j : inter){
            ans.push_back(j);
        }
        return ans;
    }
};