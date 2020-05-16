#include <bits/stdc++.h>
using namespace std;
/*
    Problem link ->
    https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

    Tested on GFG
*/

int spanningTree(int V,int E,vector<pair<int,pair<int,int>>> edg);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector<pair<int,pair<int,int>>> edg(E);
        for(int i = 0; i < E; i++){
            cin >> edg[i].first >> edg[i].second.first >> edg[i].second.second;
            edg[i].first--;
            edg[i].second.first--;
        }
        cout<<spanningTree(V,E,edg)<<endl;
    }
    return 0;
}

int find(int x,int par[]){
    if(par[x] == x){
        return x;
    }
    par[x] = find(par[x],par);
    return par[x];
}

void unionSet(int parentX,int parentY,int par[],int rank[]){
    if(rank[parentX] > rank[parentY]){
        par[parentY] = parentX;
    }else if(rank[parentX] < rank[parentY]){
        par[parentX] = parentY;
    }else{
        par[parentX] = parentY;
        rank[parentY]++;
    }
}

int spanningTree(int v,int e,vector<pair<int,pair<int,int>>> edg){
    int par[v],rank[v];
    for(int i = 0; i < v; i++){
        par[i] = i;
        rank[i] = 1;
    }
    sort(edg.begin(),edg.end(),[](pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)->bool{
       return a.second.second < b.second.second; 
    });
    int cost = 0,edgCount = 0;
    for(int i = 0; i < edg.size() && edgCount < (v - 1); i++){
          int src = edg[i].first;
          int dest = edg[i].second.first;
          int w = edg[i].second.second;
          int parentX = find(src,par);
          int parentY = find(dest,par);
          if(parentX != parentY){
              unionSet(parentX,parentY,par,rank);
              cost += w;
              edgCount++;
          }
    }
    return cost;
}