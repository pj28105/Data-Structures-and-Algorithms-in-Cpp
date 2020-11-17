#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/duplicate-zeros/

    Tested on Leetcode!
*/
class Solution {
public:
    void duplicateZeros(vector<int>& a) {
        if(a.size() <= 1){
            return;
        }
        int e = a.size() - 1,s = 0;   
        while(s < e){
            if(a[s] == 0){
                e--;
            }
            s++;
        }
        int fill = a.size() - 1;
        if(s == e){
            a[fill] = a[e];
            fill--;
            e--;
        }
        while(e >= 0){
            if(a[e] == 0){
                a[fill] = 0;
                a[fill - 1] = 0;
                fill -= 2;
            }else{
                a[fill] = a[e];
                fill--;
            }
            e--;
        }
        return;
    }
};