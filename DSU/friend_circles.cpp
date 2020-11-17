#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://leetcode.com/problems/friend-circles/

    Tested on leetcode.
*/

int find(int par[],int i){
    if(par[i] == i)
        return i;
    
    par[i] = find(par,par[i]);
    return par[i];
}
void unionSet(int par[],int rank[],int i,int j){
    int parentI = find(par,i);
    int parentJ = find(par,j);
    
    if(parentI == parentJ){
        return;
    }
    
    if(rank[parentI] < rank[parentJ]){
        par[parentI] = parentJ;
    }
    else if(rank[parentI] > rank[parentJ]){
        par[parentJ] = parentI;
    }else{
        par[parentJ] = parentI;
        rank[parentI]++;
    }
}
int findCircleNum(vector<vector<int>>& a) {
    int r = a.size(),c = a[0].size();
    int par[r],rank[r];
    for(int i = 0; i < r; i++){
        par[i] = i;
        rank[i] = 1;
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] == 1){
                unionSet(par,rank,i,j);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < r; i++){
        if(par[i] == i){
            ans++;
        }
    }
    return ans;
}