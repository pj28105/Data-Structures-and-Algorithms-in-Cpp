#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
    
    This linear space solution do check out its constant space solution too!
    Tested on GFG!
*/
int ans[10000001];
int trappingWater(int a[], int n){
    if(n == 0 || n == 1){
        return 0;
    }
    ans[0] = 0;
    ans[n - 1] = 0;
    int currMax = a[0];
    for(int i = 1; i < n - 1; i++){
        if(a[i] <= currMax){
            ans[i] = currMax - a[i];
        }else{
            ans[i] = 0;
            currMax = a[i];
        }
    }
    int sum = 0;
    currMax = a[n - 1];
    for(int i = n - 2; i >= 1; i--){
        int val = currMax - a[i];
        if(val >= 0){
           ans[i] = min(val,ans[i]);
        }else{
            ans[i] = 0;
            currMax = a[i];
        }
        sum += ans[i];
    }
    return sum;
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