#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = INT_MAX;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0
    Article link->
        https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

    Note->   
    1) Floyd warshall and Bellman ford can detect negative cycles too!
        Article link
            https://www.geeksforgeeks.org/detecting-negative-cycle-using-floyd-warshall/
    2)If shortest path for vertex v - v is negative then graph has negative cycle!
    Tested on GFG
*/
int main(){
    int t;
    cin >> t;
    while(t--){
        int v;
        cin >> v;
        vector<vector<ll>> g(v,vector<ll>(v));
        vector<vector<ll>> dist(v,vector<ll>(v,inf));
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                cin >> g[i][j];
                dist[i][j] = g[i][j];
            }
        }
        for(int k = 0; k < v; k++){
            for(int i = 0; i < v; i++){
                for(int j = 0; j < v; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                cout << dist[i][j] << " ";
             }
            cout << endl;
        }   
    }
	return 0;
}