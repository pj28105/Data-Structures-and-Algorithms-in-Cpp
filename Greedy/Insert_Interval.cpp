#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/63/sorting-and-searching-4/445/
    
    Tested on Leetcode!
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& n) {
        if(a.empty()){
            return {n};
        }
        vector<vector<int>>ans;
        int s = -1,e = -1;
        bool merged = 0;
        for(int i = 0; i < a.size(); i++){
            if(!merged && a[i][0] >= n[0]){
                if(i > 0 && !(e < n[0] || n[1] < s)){
                    s = min(s,n[0]);
                    e = max(n[1],e);
                }else{
                    if(i != 0)
                        ans.push_back({s,e});
                    s = n[0],e = n[1];
                }
                merged = 1;
            }else if(i == 0){
                s = a[i][0],e = a[i][1];
            }
            if((e < a[i][0] || a[i][1] < s)){
                ans.push_back({s,e});
                s = a[i][0],e = a[i][1];
            }else{
                s = min(s,a[i][0]);
                e = max(a[i][1],e);
            } 
        }
        if(!merged){
            if((e < n[0] || n[1] < s)){
                ans.push_back({s,e});
                ans.push_back(n);
            }else{
                s = min(s,n[0]);
                e = max(n[1],e);
                ans.push_back({s,e});
            }
            return ans;
        }
        ans.push_back({s,e});
        return ans;
    }
};