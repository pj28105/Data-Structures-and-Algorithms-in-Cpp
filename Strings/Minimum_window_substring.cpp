#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/59/array-and-strings/345/
    
    Tested on Leetcode!
*/
class Solution
{
public:
	string minWindow(string s, string t)
	{
		if (s.empty() || t.empty())
		{
			return "";
		}
		int beg = -1, ans = INT_MAX;
		int i = 0, j = 0;
		int freq[256] = {0},currfreq[256] = {0};
        for (char i : t)
		{
            freq[i]++;
		}
		int cnt = 0;
		while (i < s.length())
		{
			if (freq[s[i]] > 0)
			{
				currfreq[s[i]]++;
				if(currfreq[s[i]] == freq[s[i]]){
                    cnt += freq[s[i]];
                }
				while (freq[s[j]] == 0 || currfreq[s[j]] > freq[s[j]])
				{
					if (freq[s[j]] > 0)
					{
						currfreq[s[j]]--;
					}
					j++;
				}
			}
			if (cnt == t.length())
			{
				if (ans > (i - j + 1))
				{
					ans = i - j + 1;
					beg = j;
				}
			}
			i++;
		}
		return beg == -1 ? "" : s.substr(beg, ans);
	}
};
