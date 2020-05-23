#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<vector<int>>a (n,vector<int>(3));
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for(int i = 1; i < n; i++){
        a[i][0] += max(a[i - 1][1],a[i - 1][2]);
        a[i][1] += max(a[i - 1][2],a[i - 1][0]);
        a[i][2] += max(a[i - 1][1],a[i - 1][0]);
    }
    cout << max({ a[n - 1][0],a[n - 1][1],a[n - 1][2] }) << endl;
}