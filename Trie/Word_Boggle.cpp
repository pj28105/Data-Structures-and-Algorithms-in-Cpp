#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://leetcode.com/problems/word-search-ii/
        
        GFG Preactice poblem has wrong testcases but have look on editorial
        https://www.geeksforgeeks.org/boggle-set-2-using-trie/

        Tested on Leetocde
*/

class Trie{
  public:
    unordered_map<char,Trie*> ma;
    bool isEnd;
    Trie(){
        this->isEnd = 0;
    }
    void insert(string s){
        Trie* curr = this;
        for(auto i : s){
            if(curr->ma.count(i) == 0){
                curr->ma[i] = new Trie();
            }
            curr = curr->ma[i];
        }
        curr->isEnd = 1;
        return;
    }
};

class Solution {
public:
    int row,col;
    void dfs(vector<vector<bool>>&vis,unordered_set<string>&se,vector<vector<char>>& a,int i,int j,Trie* root,string& curr){
        if(root->isEnd){
            se.insert(curr);
        }
        vis[i][j] = 1;       
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int k = 0; k < 4; k++){
            int curri = i + dir[k][0];
            int currj = j + dir[k][1];
            if(!(curri < 0 || currj < 0 || curri >= row || currj >= col) && !vis[curri][currj]){
                if(root->ma.find(a[curri][currj]) != root->ma.end()){
                    curr.push_back(a[curri][currj]);
                    dfs(vis,se,a,curri,currj,root->ma[a[curri][currj]],curr);
                    curr.pop_back();
                }
            }
        }
        vis[i][j] = 0;
        return;
    }

    vector<string> findWords(vector<vector<char>>& a, vector<string>& w) {
        if(w.empty() || a.empty() || a[0].empty()){
            return {};
        }
        Trie* root = new Trie();
        for(auto i : w){
            root->insert(i);
        }
        row = a.size();
        col = a[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col));
        unordered_set<string>se;
        string curr = "";
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(root->ma.find(a[i][j]) != root->ma.end()){
                    curr.push_back(a[i][j]);
                    dfs(vis,se,a,i,j,root->ma[a[i][j]],curr);
                    curr.pop_back();
                }
            }
        }
        vector<string> ans;
        for(auto i : se){
            ans.emplace_back(i);
        }
        return ans;
    }
};