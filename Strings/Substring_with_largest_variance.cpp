/*
    Problem link-> https://leetcode.com/problems/substring-with-largest-variance/

    Tested on leetcode!

    Most recently asked Amazon Question!
*/
class Solution {
public:
    int largestVariance(string s) {
        int freq[26] = {0};
        for(char c : s) {
            freq[c - 'a']++;
        }
        int maxVariance = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(i != j && freq[i] > 0 && freq[j] > 0){
                    int minorCharCnt = 0, majorCharCnt = 0, remMinorChar = freq[i];
                    for(char c : s){
                        int currCharIndex = c - 'a';
                        if(currCharIndex == i || currCharIndex == j){
                            if(currCharIndex == i){
                                minorCharCnt++;
                                remMinorChar--;
                            }
                            if(currCharIndex == j){
                                majorCharCnt++;
                            }
                            if(minorCharCnt > majorCharCnt && remMinorChar > 0){
                                minorCharCnt = 0;
                                majorCharCnt = 0;
                            }
                            if(minorCharCnt > 0 && majorCharCnt > 0){
                                maxVariance = max(maxVariance, majorCharCnt - minorCharCnt);   
                            }
                        }
                    }
                }
            }
        }
        return maxVariance;
    }
};