#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1
    
    It can also be solved using dp,this solution computes nth catlan number using the formula
    with the help of fermats little theorem in nlogn

    Formula for nth catlan number  2n!/((n + 1)! * n!)
*/


 // } Driver Code Ends


// Functiuon to return number of trees

bool isCompute = 0;
const int mod = 1e9 + 7,MAX = 2001;
int fact[MAX],invFact[MAX];


int power(int a,int b){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = (a * (long long)res) % mod;
        }
        a = (a * (long long)a) % mod;
        b = b/2;
    }
    return res;
}

void compute(){
    fact[1] = 1;
    invFact[1] = 1;
    for(int i = 2; i < MAX; i++){
        fact[i] = (i * (long long)fact[i - 1]) % mod;
        invFact[i] = power(fact[i],mod - 2);
    }
}

int numTrees(int n) {
    if(n == 0){
        return 1;
    }
    if(!isCompute){
        compute();
        isCompute = 1;
    }
    /*
        2n!/((n + 1)! * n!)
    */
    int ans = (fact[2 * n] * ((invFact[n + 1] * (long long)invFact[n]) % mod) ) % mod;
    return ans;
}

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends