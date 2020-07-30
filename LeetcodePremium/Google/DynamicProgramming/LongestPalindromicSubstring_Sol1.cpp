#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/451/
    
    Tested on Leetcode!
*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
        {
            return "";
        }
        int st = 0, se = 0, len = 1;
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = 1;
        }
        for (int i = s.length() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                if (s[i] == s[j])
                {
                    if (dp[i + 1][j - 1] + 2 == (j - i + 1))
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                if (len < dp[i][j])
                {
                    st = i, se = j;
                    len = dp[i][j];
                }
            }
        }
        string pref = "", suff = "";
        while (st <= se && len > 0)
        {
            if (st == se)
            {
                pref += s[st];
                break;
            }
            if (s[st] == s[se])
            {
                pref += s[st];
                suff = s[se] + suff;
                st++, se--;
                len -= 2;
            }
            else if (dp[st][se - 1] > dp[st + 1][se])
            {
                se--;
            }
            else
            {
                st++;
            }
        }
        return pref + suff;
    }
};