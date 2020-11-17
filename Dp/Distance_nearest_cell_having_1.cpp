#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

    This problem can also be solved with bfs (check Graphs folder on github)!

    Tested on GFG
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
    vector<vector<int>>dp(row,vector<int>(col,1e9));
    int curri = -1,currj = -1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(a[i][j] == 1){
                dp[i][j] = 0;
            }
            if(i > 0){
                dp[i][j] = min(i - (i - 1) + dp[i - 1][j],dp[i][j]);
            }
            if(j > 0){
                dp[i][j] = min(j - (j - 1) + dp[i][j - 1],dp[i][j]);
            }
        }
    }
    for(int i = row - 1; i >= 0; i--){
        for(int j = col - 1; j >= 0; j--){
            if(a[i][j] == 1){
                dp[i][j] = 0;
            }
            if((i + 1) < row){
                dp[i][j] = min((i + 1) - i + dp[i + 1][j],dp[i][j]);
            }
            if((j + 1) < col){
                dp[i][j] = min((j + 1) - j + dp[i][j + 1],dp[i][j]);
            }
        }
    }
    print(dp,row,col);
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