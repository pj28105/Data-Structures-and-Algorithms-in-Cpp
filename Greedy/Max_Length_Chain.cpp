#include <bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/max-length-chain/1

    Tested on GFG
    Note->
    1) This problem is a variant of activity selection problem.
    2) It can be solved with dp too in o(n^2) check out its solution in DP folder!
*/
struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}

int maxChainLen(struct val a[],int n){
    sort(a,a + n,[](val x,val y)->bool{
        if(x.second != y.second)
            return x.second <= y.second;
        return x.first <= y.first;
    });
    int ans = 0,currst = -1;
    for(int i = 0; i < n; i++){
        if(a[i].first > currst){
            currst = a[i].second;
            ans++;
        }
    }
    return ans;
}