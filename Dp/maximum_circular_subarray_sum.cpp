#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://leetcode.com/problems/maximum-sum-circular-subarray/
     
     Tested on Leetcode and GFG
    Note-> Remeber the edge case when all numbers are negative  don't invert the signs
*/

long long kadane(long long a[],int n,int sign){
    long long currsum = 0,ma = numeric_limits<long long>::min();
    for(int i = 0; i < n; i++){
        currsum += (a[i] * sign);
        ma = max(currsum,ma);
        if(currsum < 0)
            currsum = 0;
    }
    return ma;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a[n],total = 0;
        bool positive = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] >= 0){
                positive = 1;
            }
            total += a[i];
        }
        long long sum1 = kadane(a,n,1);
        long long sum2 = positive ? total + kadane(a,n,-1) : numeric_limits<long long>::min();
        cout << max(sum1,sum2) << endl;
    }
	return 0;
}