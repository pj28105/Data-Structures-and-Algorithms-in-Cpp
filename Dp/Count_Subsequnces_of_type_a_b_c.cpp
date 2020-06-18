#include<bits/stdc++.h>
using namespace std;
/*  
    Problem link->
        https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1
    
    Tested on GFG
*/
int fun(string &str);

const int mod = 1e9 + 7;
int fun(string &s) {
    long long a = 0,b = 0,c = 0;
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            a = (((2 * a) % mod) + 1) % mod;
        }else if(s[i] == 'b'){
            b = (((2 * b) % mod) + a) % mod; 
        }else if(s[i] == 'c'){
            c = (((2 * c) % mod) + b) % mod;
        }
    }
    return c;
}
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<fun(s)<<endl;
    }
	return 0;
}