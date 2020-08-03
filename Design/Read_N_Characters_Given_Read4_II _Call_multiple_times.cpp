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
    char r_buff[4];
    int in = 0,siz = 0;
    
    int read(char *buf, int n) {
        for(int i = 1; i <= n; i++){
            if(in >= siz && (n - i + 1) >= 4){
                siz = read4(buf + i - 1);
                if(siz == 0){
                    return i - 1;
                }
                i += siz - 1;
                siz = 0;
            }else{
                if(in >= siz){
                    siz = read4(r_buff);
                    if(siz == 0){
                        return i - 1;
                    }
                    in = 0;
                }
                buf[i - 1] = r_buff[in++];
            }
        }
        return n;
    }
};