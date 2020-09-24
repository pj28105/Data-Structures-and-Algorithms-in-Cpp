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
    void dfs(vector<vector<string>>&result,unordered_map<string,vector<string>>&parents,vector<string>&aux,string& e,int dist){
        
        aux.push_back(e);
        if(dist == 1){
            result.push_back(aux);
        }
        for(auto j : parents[e]){
            dfs(result,parents,aux,j,dist - 1);
            
        } 
        aux.pop_back();
        return;
    }
    vector<vector<string>> findLadders(string b, string e, vector<string>& list) {
        unordered_map<string,vector<string>>parents;
        unordered_map<string,int>dist;
        unordered_map<string,vector<string>>g;
        for(int i = 0; i < list.size(); i++){
            string temp = list[i];
            for(int j = 0; j < list[i].length(); j++){
                char tempChar = temp[j];
                temp[j] = '*';
                g[temp].push_back(list[i]);
                temp[j] = tempChar;
            }
        }
        queue<string>q;
        q.push(b);
        dist[b] = 1;
        while(!q.empty()){
            string curr = q.front();
            if(curr == e){
                break;
            }
            q.pop();
            string temp = curr;
            for(int i = 0; i < curr.length(); i++){
                char tempChar = temp[i];
                temp[i] = '*';
                for(auto j : g[temp]){
                    if(!dist.count(j)){
                        parents[j].push_back(curr);
                        dist[j] = dist[curr] + 1;
                        q.push(j);
                    }else if(dist[j] == (dist[curr] + 1)){
                        parents[j].push_back(curr);
                    }
                }
                temp[i] = tempChar;
            }
        }
        if(!dist.count(e)){
            return {};
        }
        vector<vector<string>>result;
        vector<string>aux;
        dfs(result,parents,aux,e,dist[e]);
        for(int i = 0; i < result.size(); i++){
            reverse(result[i].begin(),result[i].end());
        }
        return result;
    }
};