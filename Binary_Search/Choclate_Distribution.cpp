#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    Problem link->
        https://www.hackerrank.com/contests/codeshala-pps-24/challenges/chocolate-distribution-problem-4
    
    Note-> This solution can be more optimized to nlogn check out solution on geeks!
            (Check greedy solution to problem on github)
    Tested on Hackerrank
*/

typedef long long ll; 
bool check(ll a[],ll mid,ll n,ll m){
    for(int i = 0; i < n; i++){
        int in = (upper_bound(a + (i + 1),a + n,a[i] + mid) - a);
        in--;
        if((in - i + 1) >= m){
            return 1;
        }
    }
    return false;
}

int main() {
    ll n,m;
    cin >> n;
    ll a[n];
    ll s = 0,e = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        e += a[i];
    }
    cin >> m;
    sort(a,a + n);
    ll ans = -1;
    while(s <= e){
        ll mid = (s + e) >> 1;
        if(check(a,mid,n,m)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}