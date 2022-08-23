#include<bits/stdc++.h>
using namespace std;

/*
    Problem link link->
        https://leetcode.com/problems/word-ladder/

    Checkout more optimized solution on leetcode!

    Note-> This problem is in from Amazon sde test serise. GFG has wrong testcases for this problem.
        Don't look at the GFG editoral too.

        2) Do look at its harder version i.e word ladder 2 on leetcode. Check its solution on github.
            This version requires BFS,DFS,DP.

    Tested on Leetcode
*/

class Solution {
public:
    int ladderLength(string b, string e, vector<string>& list) {
        unordered_set<string>vis;
        unordered_map<string,vector<string>>paths;
        for(int i = 0; i < list.size(); i++){
            string temp = list[i];
            for(int j = 0; j < list[i].length(); j++){
                char tempChar = temp[j];
                temp[j] = '*';
                paths[temp].push_back(list[i]);
                temp[j] = tempChar;
            }
            vis.insert(list[i]);
        }
        if(!vis.count(e)){
            return 0;
        }
        vis.clear();
        queue<string>q;
        q.push(b);
        vis.insert(b);
        int moves = 0;
        while(!q.empty()){
           moves++;
           int n = q.size();
           while(n--){
               string curr = q.front();
               q.pop();
               if(curr == e){
                   return moves;
               }
               for(int i = 0; i < curr.length(); i++){
                   char tempChar = curr[i];
                   curr[i] = '*';
                   for(auto j : paths[curr]){
                       if(!vis.count(j)){
                           if(j == e){
                               return moves + 1;
                           }
                           q.push(j);
                           vis.insert(j);
                       }
                   }
                   curr[i] = tempChar;
               }
           }
        }
        return 0;
    }
};