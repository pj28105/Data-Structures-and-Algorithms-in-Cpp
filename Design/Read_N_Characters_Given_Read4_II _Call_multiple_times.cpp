#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
    
    Tested on Leetcode!

    This is the most optimized code for this problem!

    See this->
        https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/discuss/188293/Google-follow-up-question.-Speed-up-the-copy.

*/


/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char temp[4];
    int size,tempIdx;
    Solution(){
        this->size = 0;
        this->tempIdx = 0;
    }
    int read(char *buf, int n) {
        int bufIdx = 0,cnt = 0;
        while(tempIdx < size && cnt < n){
           buf[bufIdx] = temp[tempIdx];
           tempIdx++;
           bufIdx++;
           cnt++;
       }
       while(cnt < n){
           int fill = read4(buf + bufIdx);
           cnt += fill;
           bufIdx += fill;
           if(fill < 4){
               break;
           }
       }
       if(cnt > n){
           size = cnt - n;
           tempIdx = 0;
           for(int i = bufIdx - size; i < bufIdx; i++){
               temp[i - (bufIdx - size)] = buf[i];
           }
       }
       return min(cnt,n); 
    }
};