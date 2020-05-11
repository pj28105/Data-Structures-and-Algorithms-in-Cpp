#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/minimum-swaps/1/?track=amazon-graphs&batchId=192
*/

int minSwaps(int A[], int N);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

int minSwaps(int a[], int n){
    unordered_map<int,int> ma;
    int aux[n];
    for(int i = 0; i < n; i++){
        ma[a[i]] = i;
        aux[i] = a[i];
    }
    int ans = 0;
    sort(aux,aux + n);
    for(int i = 0; i < n; i++){
        if(aux[i] != a[i]){
            ans ++;
            int j = ma[aux[i]];
            swap(a[j],a[i]);
            ma[a[j]] = j;
        }
    }
    return ans;
}