#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    while(q--){
        int toFind;
        cin >> toFind;
        int l = -1,r = n;
        while((l + 1) < r){
            int mid = l + (r - l)/2;
            if(a[mid] < toFind){
                l = mid;
            }else{
                r = mid;
            }
        }
        cout << r + 1 << endl;
    }
}