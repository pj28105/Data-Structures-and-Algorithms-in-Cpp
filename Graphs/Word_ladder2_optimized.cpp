#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/word-ladder-ii/

    Source-> (Checkout other possible solutions too)
        https://www.interviewbit.com/problems/word-ladder-ii/

     Tested on Leetcode
*/

class Solution {
public:
    void dfs(unordered_map<string,vector<string>>&par,vector<string>&path,vector<vector<string>>&ans,string s){
        if(par[s].empty()){
            ans.push_back(path);
            return;
        }
        for(string i : par[s]){
            path.push_back(i);
            dfs(par,path,ans,i);
            path.pop_back();
        }
        return;
    }
    vector<vector<string>> findLadders(string s, string d, vector<string>& dict) {
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
        unordered_map<string,int>dist;
        unordered_map<string,vector<string>>par;
        queue<string> q;
        q.push(d);
        dist[d] = 0;
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(curr == s){
                break;
            }
            for(string i : g[curr]){
                if(dist.find(i) == dist.end()){
                    par[i].push_back(curr);
                    dist[i] = dist[curr] + 1;
                    q.push(i);
                }else if(dist[i] == (dist[curr] + 1)){
                    par[i].push_back(curr);
                }
            }
        }
        if(dist.find(s) == dist.end()){
            return {};
        }
        vector<vector<string>> ans;
        vector<string>path;
        path.push_back(s);
        dfs(par,path,ans,s);
        return ans;
    }
};