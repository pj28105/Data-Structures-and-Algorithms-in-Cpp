#include<bits/stdc++.h>
using namespace std;
/*
    This Problem is now hidden on Hackereath.
    But i have uploaded the screenshot of this problem check ScreenShot folder!

    Tested on Hackerarth.
*/
long long ans = 0;
pair<int,int> dfs(int s,vector<bool>&vis,vector<pair<int,int>>g[]){
	vis[s] = 1;
	pair<int,int> curr = {0,0};
	for(pair<int,int>v : g[s]){
		if(!vis[v.first]){
			pair<int,int> aux = dfs(v.first,vis,g);
			if(v.second & 1){
				ans += curr.first * aux.first;
				ans += curr.second * (aux.second + 1);
				curr.first += aux.second + 1;
				curr.second += aux.first;
			}else{
				ans += curr.first * (aux.second + 1);
				ans += curr.second * (aux.first);
				curr.first += aux.first;
				curr.second += (aux.second + 1);
			}
		}
	}
	ans += curr.first;
	return curr;
}

int main(void){
	int v;
	cin >> v;
	vector<pair<int,int>>g[v];
	for(int i = 0; i < (v - 1); i++){
		int a,b,w;
		cin >> a >> b >> w;
		a--,b--;
		g[a].push_back({ b, w});
		g[b].push_back({ a, w});
	}
	vector<bool> vis(v);
	dfs(5,vis,g);
	cout << ans << endl;
	
}