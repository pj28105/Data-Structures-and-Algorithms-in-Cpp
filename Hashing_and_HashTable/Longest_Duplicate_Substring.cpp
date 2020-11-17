#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/longest-duplicate-substring/
    

    Note-> Different substrings can give same hash!
    Tested on Leetcode!
*/
const int mod = 1e9 + 7; 
const int p = 31;
const int MAX = 100005;
long long int pow_p[MAX];
class Solution {
public:
    bool isComputed = 0;
    
    void pre(){
        pow_p[0] = 1;
        for(int i = 1; i < MAX; i++){
            pow_p[i] = (pow_p[i - 1] * p) % mod;
        }
    }
    
    int check(string s,int len){
        int n = s.length();
        unordered_map<int,vector<int>>ma;
        int currhash = 0;
        for(int i = 0; i < len; i++){
            currhash = (currhash + ((pow_p[len - i - 1] * int(s[i])) % mod)) % mod; 
        }
        ma[currhash].emplace_back(0);
        for(int i = len; i < n; i++){
            currhash = ((currhash - ((int(s[i - len]) * pow_p[len - 1]) % mod)) + mod) % mod;    
            currhash = (((currhash * pow_p[1]) % mod) + int(s[i])) % mod;
            auto it = ma.find(currhash);
            if(it != ma.end()){
                for(int x : it->second){
                    bool match = 1;
                    int st = i - len + 1;
                    for(int j = 0; j < len; j++){
                        if(s[x + j] != s[st + j]){
                            match = 0;
                            break;
                        }
                    }
                    if(match){
                        return x;
                    }
                }
            }else{
                ma[currhash].emplace_back(i - len + 1);
            }
        }
        return -1;
    }
    
    string longestDupSubstring(string s) {
        if(!isComputed){
            pre();
            isComputed = 1;
        }
        int st = 1,e = s.length();
        int stIndex = -1,maxLen = 0;
        string ans = "";
        while(st <= e){
            int mid = (st + e)/2;
            int currSt = check(s,mid);
            if(currSt == -1){
                e = mid - 1;
            }else{
                stIndex = currSt;
                maxLen = mid;
                st = mid + 1;
            }
        }
        return stIndex == -1 ? "" : s.substr(stIndex,maxLen);
    }
};