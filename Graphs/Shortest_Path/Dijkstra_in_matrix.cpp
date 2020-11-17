#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1
     
     Tested on GFG
*/

int shortest(vector<vector<int> > grid ,int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > grid(n);

        for (int i = 0; i < n; i++) 
        {
            grid[i].resize(n);
            for (int j = 0; j < n; j++) 
            {
                cin >> grid[i][j];
            }
        }
        
        cout << shortest(grid,n) << endl;
    }
    return 0;
}

int shortest(vector<vector<int> > a, int n) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
    vector<vector<bool>>vis(n,vector<bool>(n));
    dist[0][0] = a[0][0];
    q.push({ a[0][0], 0});
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        pair<int,int> curr = q.top();
        q.pop();
        int ci = curr.second/n;
        int cj = curr.second % n;
        if(!vis[ci][cj]){
            vis[ci][cj] = 1;
            for(int k = 0; k < 4; k++){
                int i = ci + dir[k][0];
                int j = cj + dir[k][1];
                if(i >= 0 && i < n && j >= 0 && j < n){
                    if(!vis[i][j] && dist[i][j] > dist[ci][cj] + a[i][j]){
                        dist[i][j]  = dist[ci][cj] + a[i][j];
                        q.push({ dist[i][j],i * n + j });
                    }
                }
            }
        }
    }
    return dist[n - 1][n - 1];
}