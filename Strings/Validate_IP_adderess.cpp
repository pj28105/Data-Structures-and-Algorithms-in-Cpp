#include<bits/stdc++.h>
using namespace std;

/*
    Problem link-> https://leetcode.com/problems/validate-ip-address/
    Tested on Leetcode
*/
class Solution {
public:
    vector<string> split(string s,char c){
        vector<string> a;
        string aux = "";
        for(auto i : s){
            if(i == c){
                if(aux.length() == 0 || aux.length() > 4){
                    return {};
                }
                a.push_back(aux);
                aux = "";
            }else{
                if(aux == "0" && c == '.'){
                    return {};
                }
                if(!isdigit(i)){
                    if(c == ':')
                        i = toupper(i);
                    else
                        return {};
                }
                aux += i;
            }
        }
        if(aux.length() == 0 || aux.length() > 4){
           return {};
        }
        a.push_back(aux);
        return a;
    }
    int convert16(string s){
        int currpow = 1;
        int ans = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(isdigit(s[i])){
                ans += (s[i] - '0') * currpow;
            }else if(s[i] >= 'A' and s[i] <= 'F'){
                ans += ((s[i] - 'A') + 10) * currpow;
            }else{
                return 75535;
            }
        }
        return ans;
    }
    bool checkIP4(string s){
        if(s.empty())
            return false;
        
        vector<string> a = split(s,'.');
        if(a.empty() || (int)a.size() != 4){
            return false;
        }
        for(auto i : a){
            int num = stoi(i);
            if(!(0 <= num && num <= 255)){
                return false;
            }
        }
        return 1;
    }
    bool checkIP6(string s){
        if(s.empty())
            return false;
        
        vector<string> a = split(s,':');
        if(a.empty() || (int)a.size() != 8){
            return false;
        }
        for(auto i : a){
            int num = convert16(i);
            if(!(num >= 0 && num <= 65535)){
                return false;
            }
        }
        return true;
    }
    string validIPAddress(string s) {
        if(checkIP4(s)){
            return "IPv4";
        }
        if(checkIP6(s)){
            return "IPv6";
        }
        return "Neither";
    }
};