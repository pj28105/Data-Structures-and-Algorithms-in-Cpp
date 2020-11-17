#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0

    Tested on GFG
*/

bool check(long long currAns,int a[],int n,int m){
    long long sum = 0;
    int kids = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum > currAns){
            sum = a[i];
            kids++;
        }
    }
    return (kids + 1) <= m;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        long long s = 0,e = 0;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            e += a[i];
            s = max((long long)a[i],s);
        }
        cin >> m;
        if(n < m){
            cout << -1 << endl;
            continue;
        }
        int ans = -1;
        while(s <= e){
            long long mid = s + (e - s)/2;
            if(check(mid,a,n,m)){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        cout << ans << endl;
    }
	return 0;
}