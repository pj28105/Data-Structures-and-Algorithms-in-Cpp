#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
/*
    Problem link->
        https://www.spoj.com/problems/NUMTSN/

    This Problem has very strict time limit!.
    Solution -> Don't clear Dp array every time instead don't memoize the result when
    tight is true as it's answer may me unusabe for another number.

    Tested on SPOJ
*/

typedef long long ll;
const int mod = 1e9 + 7;

int dp[51][18][18][18];

// tc => Count of 3
// sc => Count of 6
// nc => Count of 9

int solv(int n,int tight,int tc,int sc,int nc,string& s){
    if(n == -1){
        return (sc > 0 && sc == tc && tc == nc);
    }
    if(tc  > 17 || sc > 17 || nc > 17){
        return 0;
    }
    if(!tight && dp[n][tc][sc][nc] != -1){
        return dp[n][tc][sc][nc];
    }
    int limit = tight ? (s[n] - '0') : 9;
    int ans = 0;
    for(int i = 0; i <= limit; i++){
        if(i == limit && tight){
            ans = (ans + (long long)solv(n - 1,1,tc + (i == 3),sc + (i == 6),nc + (i == 9),s)) % mod;
        }else{
            ans = (ans + (long long)solv(n - 1,0,tc + (i == 3),sc + (i == 6),nc + (i == 9),s)) % mod;
        }
    }
    if(!tight)
        dp[n][tc][sc][nc] = ans;
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        long long r = solv(b.length() - 1,1,0,0,0,b);
        long long l = solv(a.length() - 1,1,0,0,0,a);
        int tc = 0,sc = 0,nc = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == '3')
                tc++;
            else if(a[i] == '6')
                sc++;
            else if(a[i] == '9')
                nc++;
        }
        if(sc > 0 && sc == tc && tc == nc)
            cout << ((r - l + mod) % mod  + 1ll) % mod<< endl;
        else
            cout << ((r - l) + mod)% mod << endl;
    }
}