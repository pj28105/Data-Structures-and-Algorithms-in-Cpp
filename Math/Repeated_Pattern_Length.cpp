#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/contest-problem/repeated-pattern-length/1/

*/
int findRepeat(int p , int q){
    if(p % q == 0){
        return 0;
    }
    map<int,int>ma;
    int currlen = 0;
    p = p % q;
    while(1){
        if(p < q){
            p  = p * 10;
            while(p < q){
                p = p * 10;
                currlen++;
            }
        }
        if(p % q == 0){
            return 0;
        }
        if(ma.find(p) == ma.end()){
            ma[p] = currlen;
        }else{
            return currlen - ma[p];
        }
        p = p % q;
        currlen++;
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int p , q ,count;
    cin>>p>>q;
    count = findRepeat(p,q);
    cout<<count<<endl;
    }
}
