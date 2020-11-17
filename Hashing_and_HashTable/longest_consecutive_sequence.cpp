/*
    Problem link ->
    https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0

    Code is tested on leetcode and GFG

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        unordered_set<int>se;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            se.insert(a[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(se.find(a[i] - 1) == se.end()){
                int len = 1,curr = a[i] + 1;
                while(se.find(curr) != se.end()){
                    curr++;
                    len++;
                }
                ans = max(ans,len);
            }
        }
        cout << ans << endl;
    }
	return 0;
}