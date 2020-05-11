#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
*/
int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends

int find(int par[],int x){
    if(par[x] == x){
        return x;
    }
    par[x] = find(par,par[x]);
    return par[x];
}

void unionSet(int x,int y,int parent[],int rank[]){
    int parentX = find(parent,x);
    int parentY = find(parent,y);
    if(rank[parentX] < rank[parentY]){
        parent[parentX] = parentY;
    }else if(rank[parentX] > rank[parentY]){
        parent[parentY] = parentX;
    }else{
        parent[parentY] = parentX;
        rank[parentX]++;
    }
    return;
}



int findIslands(vector<int> a[], int r, int c) {
    int ans = 0;
    int par[(r*c)],rank[(r*c)];
    for(int i = 0; i < r*c; i++){
        par[i] = i;
        rank[i] = 1;
    }
    int dir[8][2] = {{1,0},{-1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] == 1){
                for(int k = 0; k < 8; k++){
                    int curri = i + dir[k][0];
                    int currj = j + dir[k][1];
                    if(curri >= 0 && curri < r && currj >= 0 && currj < c){
                        if(a[curri][currj] == 1){
                           int x = curri * c + currj;
                           int y = i * c + j;
                           unionSet(x,y,par,rank);
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < (r*c); i++){
        int curri = (i / c);
        int currj = i % c;
        if(par[i] == i && a[curri][currj] == 1)
            ans++;
    }
    return ans;
}