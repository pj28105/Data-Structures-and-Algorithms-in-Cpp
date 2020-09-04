/*
    Problem link->
        https://leetcode.com/problems/repeated-substring-pattern/

    Tested on Leetcode!

    Note->
        1)This solution only checks if string can be made by substring repeation!
            a)Checkout explanation for solution
                https://leetcode.com/discuss/explore/september-leetcoding-challenge/826207/repeated-substring-pattern-oneline-solution-explained
        
        2)To find substring there are two approaches 
            a) Find divisors and then apply rolling hash  Time-> O(N*sqrt(N)) Space-> O(N)
            b) Apply lps array and apply kmp    Time-> O(N) Space-> O(N)

        Read this->
            https://leetcode.com/problems/repeated-substring-pattern/solution/  
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
         string aux = s.substr(1,s.length()) + s.substr(0,s.length() - 1);
         int lps[s.length()],i = 1,j = 0;
         memset(lps,0,sizeof(lps));
         while(i < s.length()){
             if(s[i] == s[j]){
                 lps[i] = ++j;
                 i++;
             }else{
                 if(j == 0){
                     i++;
                 }else{
                     j = lps[j - 1];
                 }
             }
         }
         i = 0,j = 0;
         while(i < aux.length()){
             if(s[j] == aux[i]){
                 i++;
                 j++;
             }else{
                 if(j == 0){
                     i++;
                 }else{
                     j = lps[j - 1];
                 }
             }
             if(j == s.length()){
                 return 1;
             }
         }
         return 0;
    }
};