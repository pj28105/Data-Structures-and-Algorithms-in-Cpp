#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/reorganize-string/

    Tested on  Leetcode!
    Linear time and constant space!
*/
class Solution
{
public:
    string reorganizeString(string s)
    {
        int freq[26], n = s.length();
        memset(freq, 0, sizeof(freq));
        int maxfreq = 0, mx_ch = 0;
        for (char c : s)
        {
            freq[c - 'a']++;
            if (maxfreq < freq[c - 'a'])
            {
                maxfreq = freq[c - 'a'];
                mx_ch = c - 'a';
            }
        }
        char ans[n + 1];
        ans[n] = '\0';
        if (maxfreq > (n + 1) / 2)
        {
            return "";
        }
        int i = 0;
        while (freq[mx_ch] > 0)
        {
            ans[i] = mx_ch + 'a';
            i += 2;
            freq[mx_ch]--;
        }
        for (int j = 0; j < 26; j++)
        {
            while (freq[j] > 0)
            {
                if (i >= n)
                {
                    i = 1;
                }
                ans[i] = j + 'a';
                i += 2;
                freq[j]--;
            }
        }
        return string(ans);
    }
};