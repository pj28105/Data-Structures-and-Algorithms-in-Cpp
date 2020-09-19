#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/reorder-data-in-log-files/
    
    Tested on Leetcode!
*/
struct comp{
    bool operator()(pair<string,string> a,pair<string,string> b) const{
        if(a.second != b.second){
            return a.second < b.second;
        }
        return a.first < b.first;
    }    
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
       priority_queue<pair<string,string>,vector<pair<string,string>>,comp>se;
       vector<string>result;
       int j;
       for(int i = logs.size() - 1; i >= 0; i--){
           string id = "";
           for(j = 0; j < logs[i].size() && logs[i][j] != ' '; j++){
               id += logs[i][j];
           }
           j++;
           if(!isdigit(logs[i][j]))
                se.push({id,logs[i].substr(j)});
           else
                result.push_back(logs[i]);
       }
       while(!se.empty()){
           result.push_back(se.top().first + " " + se.top().second);
           se.pop();
       }
       reverse(result.begin(),result.end());
       return result;
    }
};