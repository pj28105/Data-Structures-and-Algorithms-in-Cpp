#include<bits/stdc++.h>
using namespace std;

/*
    Article link->
    https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/

    Tested status false
*/


int find(int par[],int i){
    if(par[i] == i){
        return i;
    }
    par[i] = find(par,par[i]);
    return par[i];
}

void unionSet(int par[],int rank[],int parentX,int parentY){
    if(rank[parentX] < rank[parentY]){
        par[parentX] = parentY;
    }else if(rank[parentX] > rank[parentY]){
        par[parentY] = parentX;
    }else{
        par[parentX] = parentY;
        rank[parentY]++;
    }
    return;
}

bool hasCycle(int v,vector<pair<int,int>>&edg){
    int par[v],rank[v];
    for(int i = 0; i < v; i++){
        par[i] = i;
        rank[i] = 1;
    }
    for(auto i : edg){
        int parentX = find(par,i.first);
        int parentY = find(par,i.second);
        if(parentX == parentY){
            return 1;
        }
        unionSet(par,rank,parentX,parentY);
    }
    return 0;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int v,e;
        cin >> v >> e;
        vector<pair<int,int>> edg;
        for(int i = 0; i < e; i++){
            int a,b;
            cin >> a >> b;
            edg.push_back({a , b});
        }
        cout << hasCycle(v,edg) << endl;
    }
}