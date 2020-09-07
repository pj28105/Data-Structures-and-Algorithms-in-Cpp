#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/contain-virus/

    Asked in Accolite Interview!
*/
class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis,vector<pair<int,int>>&temp){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j] != 1){
            return;
        }
        temp.push_back({i,j});
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            dfs(i + dir[k][0],j + dir[k][1],grid,vis,temp);
        }
        return;
    }
    pair<int,int> bfs(vector<pair<int,int>>component,vector<vector<int>>&grid){
        int ans = 0,infect = 0;
        queue<pair<int,int>>q;
        for(auto i : component){
            q.push({i.first,i.second});
        }
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size()));
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int ci = i + dir[k][0];
                int cj = j + dir[k][1];
                if(ci >= 0 && cj >= 0 && ci < grid.size() && cj < grid[0].size()){
                    if(grid[ci][cj] == 0){
                        ans++;
                        if(!vis[ci][cj]){
                            vis[ci][cj] = 1;
                            infect++;
                        }
                    }
                }
            }
        }
        return {ans,infect};
    }
    void advance(vector<vector<int>>&grid,vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1)
                    q.push({i,j});
                vis[i][j] = 0;
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int ci = i + dir[k][0];
                int cj = j + dir[k][1];
                if(ci >= 0 && cj >= 0 && ci < grid.size() && cj < grid[0].size()){
                    if(grid[ci][cj] == 0){
                        grid[ci][cj] = 1;
                    }
                }
            }
        }
        return;
    }
    int containVirus(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size()));
        vector<vector<pair<int,int>>>components;    
        while(1){
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[i].size(); j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        vector<pair<int,int>>temp;
                        dfs(i,j,grid,vis,temp);
                        components.push_back(temp);   
                    }
                }
            }
            if(components.empty()){
                break;
            }
            int infected = -1,walls = 0,index = 0;
            for(int i = 0; i < components.size(); i++){
                pair<int,int> currInfected = bfs(components[i],grid);
                if(currInfected.second > infected){
                    infected = currInfected.second;
                    walls = currInfected.first;
                    index = i;
                }
            }
            ans += walls;
            for(auto &i : components[index]){
                grid[i.first][i.second] = -1;
            }
            advance(grid,vis);
            components.clear();
        }
        return ans;
    }
};