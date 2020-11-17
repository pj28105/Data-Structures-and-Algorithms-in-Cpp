#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits.h>
#include <math.h>
#include <utility>
#include <algorithm>
using namespace std;
 
#define mod 1000000007
#define ll long long
#define tc int t; cin >> t; while(t--)
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ERR
#ifdef ERR
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define deb(...)
#endif

/*
    Problem name->
        https://leetcode.com/problems/dungeon-game/
    
    Tested on Leetcode

    Note-> This problem can also be solved through binary search!
*/
signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int dp[n][m];
        dp[n - 1][m - 1] = 1;
        for(int i = m - 2; i >= 0; i--){
            dp[n - 1][i] = max(1,dp[n - 1][i + 1] - a[n - 1][i]);
        }
        for(int i = n - 2; i >= 0; i--){
            dp[i][m - 1] = max(1,dp[i + 1][m - 1] - a[i][m - 1]);
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = m - 2; j >= 0; j--){
                dp[i][j] = max(1,min(dp[i + 1][j],dp[i][j + 1]) - a[i][j]);
            }
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}