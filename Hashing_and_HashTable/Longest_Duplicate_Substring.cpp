#include<bits/stdc++.h>
using namespace std;
/*  
    Problem link->
        https://leetcode.com/problems/longest-duplicate-substring/
    
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
    
    string check(string s,int len){
        int n = s.length();
        int hash[n];
        unordered_map<int,int>ma;
        int currhash = 0;
        for(int i = 0; i < len; i++){
            currhash = (currhash + ((pow_p[len - i - 1] * int(s[i])) % mod)) % mod; 
        }
        ma[currhash] = 0;
        for(int i = len; i < n; i++){
            currhash = ((currhash - ((int(s[i - len]) * pow_p[len - 1]) % mod)) + mod) % mod;    
            currhash = (((currhash * pow_p[1]) % mod) + int(s[i])) % mod;
            auto it = ma.find(currhash);
            if(it != ma.end()){
                string sub1 = s.substr(it->second,len);
                string sub2 = s.substr(i - len + 1,len);
                if(sub1 == sub2){
                    return sub1;
                }
            }else{
                ma[currhash] = i - len + 1;
            }
        }
        return "";
    }
    
    string longestDupSubstring(string s) {
        if(!isComputed){
            pre();
        }
        int st = 1,e = s.length();
        string ans = "";
        while(st <= e){
            int mid = (st + e) >> 1;
            string aux = check(s,mid);
            if(aux == ""){
                e = mid - 1;
            }else{
                ans = aux;
                st = mid + 1;
            }
        }
        return ans;
    }
};