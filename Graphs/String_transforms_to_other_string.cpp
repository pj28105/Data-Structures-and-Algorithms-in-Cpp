/*
    Problem link->
        https://leetcode.com/problems/string-transforms-into-another-string/

    Tested on Leetcode!
    Very challenging!
*/
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1.empty()){
            return 1;
        }
        unordered_set<char> se;
        unordered_map<char,unordered_set<char>>g;
        for(int i = 0; i < str1.length(); i++){
            g[str1[i]].insert(str2[i]);
            se.insert(str2[i]);
        }
        for(auto i : g){
            if(i.second.size() > 1){
                return 0;
            }
        }
        if(str1 == str2 ||se.size() < 26){
            return 1;
        }
        return 0;
    }
};