#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://www.hackerrank.com/contests/codeshala-pps-24/challenges/chocolate-distribution-problem-4
    
    Tested on Hackerrank
*/

int main(void){
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a + n);
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        if((i + m - 1) < n)
            ans = min(ans,a[i + m - 1] - a[i]);
        else
            break;
    }
    cout << ans << endl;
    return 0;
}