#include <bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/max-length-chain/1
    
    Tested on GFG!
    Note->
    1) It can be solved with greedy too in o(nlogn), check out its solution in Greedy folder!
    2) This problem is a variant of activity selection problem.
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
        if(x.first != y.first)
            return x.first <= y.first;
        return x.second <= y.second;
    });
    int dp[n],ans = 0;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(a[i].first > a[j].second)
                dp[i] = max(dp[i],1 + dp[j]);
        }
        ans = max(dp[i],ans);
    }
    return ans;
}