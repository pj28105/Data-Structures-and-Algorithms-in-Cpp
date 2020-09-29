#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/amazon/82/others/3005/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int arrayToInt(vector<int>&cells){
        int num = 0,mask = 1;
        for(int i = 0; i < 8; i++){
            if(cells[i]){
                num = num | mask;
            }
            mask *= 2;
        }
        return num;
    }
    void intToArray(vector<int>&cells,int num){
        int mask = 1;
        for(int i = 0; i < 8; i++){
            cells[i] = ((num & mask) > 0); 
            mask *= 2;
        }
        return;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int curr = arrayToInt(cells);
        int nxt = 0,mask;
        vector<int>states;
        unordered_map<int,int>look;
        while(n--){
            states.push_back(curr);
            look[curr] = states.size() - 1;
            mask = 1,nxt = 0;
            for(int i = 0; i < 8; i++){    
               if(i > 0 && i < 7){
                   if((curr & (mask/2)) > 0 && (curr & (mask * 2)) > 0){
                       nxt = nxt | mask;
                   }else if((curr & (mask/2)) == 0 && (curr & (mask * 2)) == 0){
                       nxt = nxt | mask;
                   }
               }
               mask *= 2;
            }
            curr = nxt;
            if(look.count(curr)){
                break;
            }
        }
        if(n > 0){
            int cycleLen = (states.size() - 1) - look[curr] + 1;
            n = n % cycleLen;
            intToArray(cells,states[n + look[curr]]);
        }else{
            intToArray(cells,curr);
        }
        return cells;
    }
};