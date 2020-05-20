#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://leetcode.com/problems/subarray-sums-divisible-by-k/
    Tested on Leercode
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int ma[k + 1];
        memset(ma,0,sizeof(ma));
        int sum = 0,ans = 0;
        ma[0] = 1;
        for(int i = 0; i < a.size(); i++){
            if(a[i] >= 0){
                sum = (sum + a[i]) % k;
            }else{
                sum = ((sum - (abs(a[i]) % k)) + k) % k;
            }
            ans += ma[sum];
            ma[sum]++;
        }   
        return ans;
    }
};