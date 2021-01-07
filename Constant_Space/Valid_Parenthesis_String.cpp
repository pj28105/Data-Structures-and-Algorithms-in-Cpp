/*
    Problem link->
        https://leetcode.com/problems/valid-parenthesis-string/
    
    Must do problem before interview!
    Tested on Leetcode!
*/
class Solution {
public:
    bool checkValidString(string s) {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                if(cnt > 0){
                    cnt--;
                }else{
                    return false;
                }
            }else{
                cnt++;
            }
        }
        cnt = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '('){
                if(cnt > 0){
                    cnt--;
                }else{
                    return 0;
                }
            }else{
                cnt++;
            }
        }
        return 1;
    }
};