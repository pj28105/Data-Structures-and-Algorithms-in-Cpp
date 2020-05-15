#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://leetcode.com/problems/word-search-ii/
        
        GFG Preactice poblem has wrong testcases but have look on editorial
        https://www.geeksforgeeks.org/boggle-set-2-using-trie/

        Tested on Leetocde
*/

inline bool isSafe(int i,int j,int r,int c){
    if(i < 0 || j < 0 || i >= r || j >= c){
        return 0;
    }
    return 1;
}

class Trie{
    public:
        unordered_map<char,Trie*> ma;
        bool isEnd = 0;
        Trie(){
            for(int i = 0; i < 26; i++){
                ma['a' + i] = NULL;
            }
            isEnd = 0;
        }
        void insert(string s,Trie* root){
            for(char c : s){
                if(!root->ma[c]){
                    root->ma[c] = new Trie();
                }
                root = root->ma[c];
            }
            root->isEnd = 1;
            return;
        }
        void dfs(vector<string>& ans,string curr,Trie* root,int i,int j,vector<vector<bool>>&vis,vector<vector<char>>& a,int r,int c){
            if(!root){
                return;
            }
            if(root->isEnd){
                ans.push_back(curr);
                root->isEnd = 0;
            }
            vis[i][j] = 1;
            int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for(int k = 0; k < 4; k++){
                int ci = i  + dir[k][0];
                int cj = j + dir[k][1];
                if(isSafe(ci,cj,r,c) && root->ma[a[ci][cj]]){
                    if(!vis[ci][cj]){
                        dfs(ans,curr + a[ci][cj],root->ma[a[ci][cj]],ci,cj,vis,a,r,c);
                    }
                }
            }
            vis[i][j] = 0;
            return;
        }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& a, vector<string>& words) {
        Trie* root = new Trie();
        for(string i : words){
            root->insert(i,root);
        }
        int r = a.size(),c = a[0].size();
        vector<string> ans;
        vector<vector<bool>> vis(r,vector<bool>(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(root->ma[a[i][j]]){
                    string curr = "";
                    curr += a[i][j];
                    root->dfs(ans,curr,root->ma[a[i][j]],i,j,vis,a,r,c);   
                }
            }
        }
        return ans;
    }
};