#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
    
	To solve this problem in one pass use LinkedHashMap(maintains insertion order).
	See Editorial @ Leetcode for reference! 
    Tested on leetcode!
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
		int freq[256];
		memset(freq, 0, sizeof(freq));
		int i = 0, j = 0, cnt = 0, ans = 0;
		while (i < int(s.length()))
		{
			if (freq[s[i]] == 0)
			{
				cnt++;
			}
			freq[s[i]]++;
			if (cnt > k)
			{
				while (cnt > k)
				{
					freq[s[j]]--;
					if (freq[s[j]] == 0)
					{
						cnt--;
					}
					j++;
				}
			}
			ans = max(ans, i - j + 1);
			i++;
		}
		return ans;
    }
};