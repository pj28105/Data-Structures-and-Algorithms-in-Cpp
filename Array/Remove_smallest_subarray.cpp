#include<bits/stdc++.h>
using namespace std;
/*
    This Problem is now hidden on Hackereath.
    But i have uploaded the screenshot of this problem check ScreenShot folder!

    Tested on Hackerarth.
*/

typedef long long ll;
int main(void){
	ll n,k;
	cin >> n >> k;
	ll a[n];
	ll sum = 0;
	unordered_set<ll>se;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = a[i] % k;
		sum += a[i];
		se.insert(a[i]);
	}
	if(sum % k == 0){
		cout << 0 << endl;
		return 0;
	}else if(se.find(sum % k) != se.end()){
		cout << 1 << endl;
		return 0;
	}
	sum = sum % k;
	unordered_map<ll,ll>ma;
	ll currSum = 0;
	ll ans = INT_MAX;
	for(int i = 0; i < n; i++){
		currSum += a[i];
		currSum = currSum % k;
		if(currSum == sum){
			ans = min(ans,(ll)(i + 1));
		}
		if(ma.find((currSum - sum + k) % k) != ma.end()){
			ans = min(ans,(ll)(i - ma[(currSum - sum + k) % k]));
		}
		ma[currSum] = i;
	}
	cout << ans << endl;
	return 0;
}