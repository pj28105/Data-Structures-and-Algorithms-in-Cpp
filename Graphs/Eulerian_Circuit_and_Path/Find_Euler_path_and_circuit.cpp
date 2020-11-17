#include<bits/stdc++.h>
using namespace std;
/*

    Problem link->
        https://leetcode.com/problems/reconstruct-itinerary/
    
    Note->
        1)In this problem it is given that eulerian path or circuit exists thats why i have not
            checked its presence!
        2)In this problem we have to find smallest lexical path so this why i have sort the 
            adjacency list for vertices!
*/
class Solution {
public:
    void dfs(string s,vector<string>&ans,unordered_map<string,vector<string>>&g,unordered_map<string,int>&outdeg){
        int siz = g[s].size();
        while(outdeg[s] != 0){
            int index = siz - outdeg[s];
            outdeg[s]--;
            dfs(g[s][index],ans,g,outdeg);
        }
        ans.push_back(s);
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        unordered_map<string,vector<string>>g;
        unordered_map<string,int> outdeg;
        for(auto i : t){
            g[i[0]].push_back(i[1]);
            outdeg[i[0]]++;
        }
        for(auto &i : g){
            sort(i.second.begin(),i.second.end());
        }
        vector<string> ans;
        dfs("JFK",ans,g,outdeg);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};