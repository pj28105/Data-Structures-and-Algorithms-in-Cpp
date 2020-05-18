#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Problem link->
    https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

    Tested on Hackerearth
*/

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v,e;
	cin >> v >> e;
	vector<pair<ll,ll>> g[v];
	for(int i = 0; i < e; i++){
		ll a,b,w;
		cin >> a >> b >> w;
		a--,b--;
		g[a].push_back({w,b});
		g[b].push_back({w,a});
	}
	vector<bool> vis(v,0);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
	q.push({0,0});
	ll cost = 0;
	while(!q.empty()){
		pair<ll,ll> curr = q.top();
		q.pop();
		if(!vis[curr.second]){
			vis[curr.second] = 1;
			cost += curr.first;
			for(auto v : g[curr.second]){
				if(!vis[v.second]){
					q.push({v.first,v.second});
				}
			}
		}
	}
	cout << cost << endl;
}