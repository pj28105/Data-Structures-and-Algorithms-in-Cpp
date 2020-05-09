#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

    This is BFS solution to the problem this problem has dp solution too.
    
    Tested on GFG and Leetcode.
*/

int rotOranges(vector<vector<int> > a, int r, int c){
    queue<pair<int,int>>q;
    vector<vector<int>> time(r,vector<int>(c,INT_MAX));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] == 2){
                q.push({i,j});
                time[i][j] = 0;
            }
        }
    }
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        for(int k = 0; k < 4; k++){
            int i = curr.first + dir[k][0];
            int j = curr.second + dir[k][1];
            if(i >= 0 && j >= 0 && i < r && j < c){
                if(a[i][j] == 1 && (time[curr.first][curr.second] + 1) < time[i][j]){
                    time[i][j] = time[curr.first][curr.second] + 1;
                    q.push({i,j});
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] == 1){
                ans = max(ans,time[i][j]);
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
}