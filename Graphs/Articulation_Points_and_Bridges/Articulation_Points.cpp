#include<bits/stdc++.h>
using namespace std;
/*

    Problem and Article link->
        https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
        
    Youtube link->
        https://www.youtube.com/watch?v=2kREIkF9UAs
        
    Tested Status False
*/

void dfs(int s,vector<bool>&vis,vector<int>g[],vector<int>&par,set<int>&AP,int& time,vector<int>&low,vector<int>&disc){
	vis[s] = 1;
	time++;
	int child = 0;
	low[s] = time;
	disc[s] = time;
	for(int v : g[s]){
		if(!vis[v]){
			par[v] = s;
			child++;
			dfs(v,vis,g,par,AP,time,low,disc);
			low[s] = min(low[s],low[v]);
			if(par[s] == -1 && child > 1){
				AP.insert(s);	
			}
			if(par[s] != -1 && disc[s] <= low[v]){
				AP.insert(s);
			}
		}else if(par[s] != v){
			low[s] = min(low[s],disc[v]);
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int v,e;
	cin >> v >> e;
	vector<int>g[v];
	for(int i = 0; i < e; i++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<bool> vis(v);
	set<int> AP;
	vector<int> par(v),low(v),disc(v);
	int time = 0;
	for(int i = 0; i < v; i++){
		if(!vis[i]){
			par[i] = -1;
			dfs(i,vis,g,par,AP,time,low,disc);
		}
	}
	cout << AP.size() << endl;
	for(auto i = AP.rbegin(); i != AP.rend(); i++){
		cout << *i << endl;
	}
}