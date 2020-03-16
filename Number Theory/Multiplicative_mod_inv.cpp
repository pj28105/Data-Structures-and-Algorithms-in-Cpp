// PJ28105
// MARK 2

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
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define deb(...)
#endif

/*
    Note :
        1) For extended Euclid make sure a > b
        2) Multiplactive modulo inverse only exsist
        when gcd(A,M) == 1 (for (A.B)mod M = 1)
*/

struct sol{
    int x,y,gcd;
};

sol extended_gcd(ll a,ll b){
    if(b == 0){
        sol ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    sol eq,ans;
    eq = extended_gcd(b,a % b);
    ans.gcd = eq.gcd;
    ans.x = eq.y;
    ans.y = eq.x - ((a/b) * eq.y);
    return ans;
}

void mmi(ll a,ll m){
    sol ans = extended_gcd(a,m);
    if(ans.gcd == 1){
        cout << "B = " << ans.x << endl;
    }else{
        cout << "Multiplicative Modulo Inverse Doesnt exsist" << endl;
    }
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
        freopen("../in.txt","r",stdin);
    #endif
    mmi(5,17);
    return 0;
}