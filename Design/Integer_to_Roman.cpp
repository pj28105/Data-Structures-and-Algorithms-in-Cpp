#include<bits/stdc++.h>
using namespace std;
/*
    Problem ->
        https://leetcode.com/problems/integer-to-roman/
    
    Tested on Leetcode!
*/
class Solution {
public:
    vector<pair<int,string>>poss;
    string intToRoman(int num) {
        if(poss.empty()){
            poss.push_back({1000,"M"});
            poss.push_back({900,"CM"});
            poss.push_back({500,"D"});
            poss.push_back({400,"CD"});
            poss.push_back({100,"C"});
            poss.push_back({90,"XC"});
            poss.push_back({50,"L"});
            poss.push_back({40,"XL"});
            poss.push_back({10,"X"});
            poss.push_back({9,"IX"});
            poss.push_back({5,"V"});
            poss.push_back({4,"IV"});
            poss.push_back({1,"I"});
        }
        string ans = "";
        for(int i = 0; i < poss.size() && num > 0; i++){
            while(poss[i].first <= num && num > 0){
                num -= poss[i].first;
                ans += poss[i].second;
            }
        }
        return ans;
    }
};