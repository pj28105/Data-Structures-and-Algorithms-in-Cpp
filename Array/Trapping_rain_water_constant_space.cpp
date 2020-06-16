#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

    This constant space solution do check out its linear space solution too!
    Tested on GFG!
*/
int trappingWater(int a[], int n){
    if(n == 0 || n == 1){
        return 0;
    }
    int ans = 0;
    int l = 0,r = n - 1,rmax = 0,lmax = 0;
    while(l <= r){
        if(a[l] < a[r]){
            if(lmax > a[l]){
                ans += lmax - a[l];
            }else{
                lmax = a[l];
            }
            l++;
        }else{
            if(rmax > a[r]){
                ans += rmax - a[r];
            }else{
                rmax = a[r];
            }
            r--;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];   
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        cout << trappingWater(a, n) << endl;       
    }
    return 0;
}