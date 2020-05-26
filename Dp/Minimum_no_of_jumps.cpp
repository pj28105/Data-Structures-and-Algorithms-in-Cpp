#include<bits/stdc++.h>
using namespace std;

int solv(int a[],int n){
    if(n == 1){
        return 0;
    }
    if(a[0] == 0){
        return -1;
    }
    if(a[0] >= n - 1){
        return 1;
    }
    int max_in = a[0],jump = 0,curr_max = a[0];
    for(int i = 1; i < n; i++){
        curr_max = max(curr_max,a[i] + i);
        if(i == max_in){
            jump++;
            if(curr_max <= max_in){
                return -1;
            }
            if(curr_max >= (n - 1)){
                return jump + 1;
            }
            max_in = curr_max;
        }
    }
    return -1;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << solv(a,n) << endl;
    }   
}