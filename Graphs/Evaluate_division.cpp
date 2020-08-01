#include<bits/stdc++.h>
using namespace std;
/*
    Problem link-> 
        https://leetcode.com/problems/evaluate-division/

    Frequently asked question in google onsite interviews!
*/
class Solution {
public:
    double inf;
    double dfs(string currdeno,string f_deno,unordered_set<string>&vis,unordered_map<string,vector<pair<string,double>>>&g){
       if(currdeno == f_deno){
           return 1.0;
       }
       vis.insert(currdeno);
       double currAns;
       for(auto i : g[currdeno]){
           if(!vis.count(i.first)){
               currAns = dfs(i.first,f_deno,vis,g);
               if(currAns != inf){
                   currAns *= i.second;
                   return currAns;
               }
           }
       }
       return inf;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q){
        inf = numeric_limits<double>::max();
        unordered_map<string,vector<pair<string,double>>>g;
        for(int i = 0; i < int(eq.size()); i++){
            g[eq[i][0]].push_back({eq[i][1],val[i]});
            g[eq[i][1]].push_back({eq[i][0],1.0/val[i]});
        }
        unordered_set<string>vis;
        vector<double> ans;
        for(auto i : q){
            string num = i[0],deno = i[1];
            if(num == deno && g.count(num)){
                ans.push_back(1.0);
            }else{
                double currAns = inf;
                vis.clear();
                vis.insert(num);
                for(auto i : g[num]){
                    currAns = dfs(i.first,deno,vis,g);
                    if(currAns != inf){
                        currAns *= i.second;
                        ans.push_back(currAns);
                        break;
                    }
                }
                if(currAns == inf){
                    ans.push_back(-1.0);
                }
            }
        }
        return ans;
    }
};