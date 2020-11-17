#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/minimize-max-difference-between-adjacent-elements-by-inserting-k-new-elements/1
    
    Tested on GFG
*/
int minimizedMaxDiff(int arr[], int n, int k);

int main()
{
    int arr[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> arr[i];
        
        int k;
        cin>>k;
        
        cout<< minimizedMaxDiff(arr,n,k) << endl;
    }
    return 1;
}

bool check(int a[],int diff,int k,int n){
    int curr = 0;
    for(int i = 1; i < n; i++){
        if(abs(a[i] - a[i - 1]) > diff){
            curr += ceil((max(a[i],a[i - 1]) - min(a[i], a[i - 1]))/(double)diff) - 1;
        }
        if(curr > k)
            return 0;
    }
    return 1;
}

int minimizedMaxDiff(int a[], int n, int k){
    bool same = 1;
    for(int i = 0; i < n - 1; i++){
        if(a[i] != a[i + 1]){
            same = 0;
            break;
        }
    }
    if(same){
        return 0;
    }
    int s = 1,e = 1000;
    int ans = 0;
    while(s <= e){
        int mid = s + (e - s)/2;
        if(check(a,mid,k,n)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return ans;
}