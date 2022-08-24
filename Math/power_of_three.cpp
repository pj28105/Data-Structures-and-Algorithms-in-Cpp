/*

    Problem link -> https://leetcode.com/problems/power-of-three/

    Tested on Leetcode
    Notes:
        1) Make sure to checkout its editorial, it explains different approaches to solve this problem
            and their potential pitfalls
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1){
            return 1;
        }
        if(n < 3){
            return 0;
        }
        return 1162261467 % n == 0;
    }
};