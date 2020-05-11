#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

    This problem can also be solved with dp (check dp folder on github)!

    Tested on GFG
    Similar logic got accepted on leetcode as well. (0-1 Matrix leetcode problem)
*/


void print(vector<vector<int>> arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}

void nearest(vector<vector<int>> a, int row, int col) {
    queue<pair<int,int>>q;
    bool vis[row][col];
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(a[i][j] == 1){
                q.push({i,j});
                vis[i][j] = 1;
                a[i][j] = 0;
            } 
        }
    }
    int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int curri = i + dir[k][0],currj = j + dir[k][1];
            if(curri >= 0 && curri < row && currj >= 0 && currj < col){
                if(!vis[curri][currj]){
                    a[curri][currj] = a[i][j] + abs(i - curri) + abs(currj - j);
                    vis[curri][currj] = 1;
                    q.push({curri,currj});
                }
            }
        }
    }
    print(a,row,col);
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> graph(row);

        for (int i = 0; i < row; i++) {
            vector<int> temp(col);
            graph[i] = temp;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        nearest(graph, row, col);
    }

    return 0;
}