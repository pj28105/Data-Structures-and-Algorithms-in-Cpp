#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3073/
    
    Tested on Leetcode!
*/
class Solution
{
public:
    string rep(string& aux, int freq)
    {
        freq--;
        //cout << aux << " " << freq << endl;
        string temp = aux;
        while (freq--)
        {
            aux += temp;
        }
        return aux;
    }

    string solv(string &s, int &i)
    {
        if (i >= s.length())
        {
            return "";
        }
        string ans = "";
        for (; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int freq = 0;
                while(s[i] >= '0' && s[i] <= '9'){
                    freq = freq * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                string aux = solv(s, i);
                ans += rep(aux, freq);
            }
            else if (s[i] == ']')
            {
                break;
            }
            else
            {
                ans += s[i];
            }
        }
        //i++;
        return ans;
    }
    string decodeString(string s)
    {
        if (s.empty())
        {
            return "";
        }
        int i = 0;
        return solv(s, i);
    }
};