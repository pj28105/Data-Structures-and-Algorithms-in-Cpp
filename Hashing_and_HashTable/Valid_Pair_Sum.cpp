#include <bits/stdc++.h> 
using namespace std; 
int ValidPair(int* array, int n) ;
/*
    Problem link->
        https://practice.geeksforgeeks.org/contest-problem/valid-pair-sum/1/
    
    Tested on GFG
*/
int ValidPair(int* array, int n) {
    vector<int> a;
    for(int i = 0; i < n; i++){
        a.push_back(array[i]);    
    }
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= 0)
            ans += n - 1 - i;
        else{
            int in = upper_bound(a.begin(),a.end(),-1*a[i]) - a.begin();
            if(in < n){
                ans += n - in;
            }
        }
    }
    return ans;
} 

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
		cout<<ValidPair(array,n)<<endl;
	}
	return 0; 
} 