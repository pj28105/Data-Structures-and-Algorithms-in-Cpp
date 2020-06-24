#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/game-of-digits/1
    
    Tested on GFG
*/
string smallestK(long long n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        long long n;
        cin>>n;
        cout<< smallestK(n) << endl;
	}
	return 1;
}

string smallestK(long long n){
    if(n == 1){
        return "1";
    }
    string ans = "";
    while(n > 1){
        bool f = 0;
        for(int i = 9; i >= 2; i--){
            if(n % i == 0){
                ans = to_string(i) + ans;
                n = n/i;
                f = 1;
                break;
            }
        }
        if(!f){
            return "-1";
        }
    }
    return ans;
}
