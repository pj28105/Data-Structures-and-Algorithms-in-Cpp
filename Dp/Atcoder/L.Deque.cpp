#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 3005;
ll dp[MAX][MAX][2];

ll solv(int s,int e,bool player,vector<ll>&a){
    if(s == e){
        if(player)
            return a[s];
        return -a[s];
    }
    if(dp[s][e][player] != INT64_MIN){
        return dp[s][e][player];
    }    
    if(player){
        ll ans = max(a[s] + solv(s + 1,e,!player,a),a[e] + solv(s,e - 1,!player,a));
        dp[s][e][player] = ans;
        return ans;
    }
    ll ans = min(solv(s + 1,e,!player,a) - a[s],solv(s,e - 1,!player,a) - a[e]);
    dp[s][e][player] = ans;
    return ans;
}

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = INT64_MIN;
            }
        }
    }
    cout << solv(0,n - 1,1,a) << endl;   
}