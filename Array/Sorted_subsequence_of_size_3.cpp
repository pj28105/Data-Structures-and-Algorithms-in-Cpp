#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/?track=amazon-arrays&batchId=192
    

    Note-> This is a constant space solution do check out its O(n) space solution on GFG!

    Tested on GFG
*/
vector<int> find3Numbers(vector<int> a, int n) {
    int first = INT_MAX,second = INT_MAX,thirdIndex = -1;
    for(int i = 0; i < n; i++){
        if(a[i] <= first){
            first = a[i];
        }
        else if(a[i] <= second){
            second = a[i];
        }else{
            thirdIndex = i;
            break;
        }
    }
    if(thirdIndex == -1){
        return {};
    }
    for(int j = 0; j < thirdIndex; j++){
        if(a[j] < second){
            return {a[j],second,a[thirdIndex]};
        }
    }
    return {};
}