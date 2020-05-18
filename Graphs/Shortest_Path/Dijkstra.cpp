#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
    https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

    Complexity -> O((E + V)Log(V)) (For Binary Heap or priority_queue)
    Can be more optimized to O(E + VLogV) (For Fibonacci Heap which has update as O(1))
    
    Note-> Implemented for directed Graph
		2)Dijkstra Algorithm works for negative edges too! But it fails for graph with negative weight cycle because
			it fails detecting the negative cycles!
		3) Floyd warshall and Bellman ford can detect negative cycles too!
    Tested on Hackerearth
*/
typedef long long ll;
const ll inf = 1e18;

int main(void){
	int v,e;
	cin >> v >> e;
	vector<pair<ll,ll>>g[v];
	for(int i = 0; i < e; i++){
		ll a,b,w;
		cin >> a >> b >> w;
		a--,b--;
		g[a].push_back({ w,b });
	}
	vector<bool> vis(v,0);
	vector<ll> dist(v,inf);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
	q.push({ 0,0 });
	dist[0] = 0;
	while(!q.empty()){
		pair<ll,ll> curr = q.top();
		q.pop();
		if(!vis[curr.second]){
			vis[curr.second] = 1;
			for(auto v : g[curr.second]){
				if(!vis[v.second] && dist[v.second] > (dist[curr.second] + v.first)){
					dist[v.second] = dist[curr.second] + v.first;
					q.push({ dist[v.second], v.second});
				}
			}
		}
	}
	for(int i = 1; i < v; i++){
		if(dist[i] == inf){
			cout << 1e9 << " ";
		}else{
			cout << dist[i] << " ";
		}
	}
	cout << endl;
}