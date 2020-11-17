#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/snakes-and-ladders/

    Tested on leetcode
*/

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &a)
    {
        int r = a.size(), c = a[0].size();
        unordered_map<int, int> ma;
        int cellno = 1;
        for (int i = r - 1, k = 0; i >= 0; i--, k++)
        {
            if (k % 2 == 0)
            {
                for (int j = 0; j < c; j++)
                {
                    ma[cellno] = a[i][j];
                    cellno++;
                }
            }
            else
            {
                for (int j = c - 1; j >= 0; j--)
                {
                    ma[cellno] = a[i][j];
                    cellno++;
                }
            }
        }
        vector<bool> vis(r * c + 1, 0);
        queue<int> q;
        q.push(1);
        int movs = -1;
        while (!q.empty())
        {
            movs++;
            int n = q.size();
            while (n--)
            {
                int curr = q.front();
                q.pop();
                if (curr == r * c)
                {
                    return movs;
                }
                for (int i = curr + 1; i <= min(curr + 6, r * c); i++)
                {
                    int nxtcell = i;
                    if (ma[i] != -1)
                    {
                        nxtcell = ma[i];
                    }
                    if (!vis[nxtcell])
                    {
                        vis[nxtcell] = 1;
                        q.push(nxtcell);
                    }
                }
            }
        }
        return -1;
    }
};