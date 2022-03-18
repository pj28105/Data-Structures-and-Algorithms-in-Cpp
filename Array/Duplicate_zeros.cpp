#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/duplicate-zeros/

    Tested on Leetcode!
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), newSize = 0, end = -1;
        bool includeLastZero = 0;
        for(int i = 0 ; i < n; i++){
            newSize += (arr[i] == 0 ? 2 : 1);
            if (arr[i] == 0 && newSize == n){
                includeLastZero = 1;
            }
            if (newSize >= n){
                newSize = n;
                end = i;
                break;
            }
        }
        int j = n - 1;
        for(int i = end; i >= 0; i--){
            if (arr[i] == 0 && (i < end || includeLastZero)){
                arr[j] = 0;
                arr[j - 1] = 0;
                j-=2;
            }else{
                arr[j] = arr[i];
                j--;
            }
        }
    }
};