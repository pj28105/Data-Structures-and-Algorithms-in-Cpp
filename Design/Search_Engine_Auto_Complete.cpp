#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/design-search-autocomplete-system/

    Tested on Leetcode!
*/
struct comp{
  bool operator()(pair<int,string> x,pair<int,string> y){
      if(x.first != y.first)
         return x.first > y.first;
       return x.second < y.second; 
  } 
};

class AutocompleteSystem {
public:
    
    string prefix = "";
    unordered_map<string,int>search_freq;
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,comp>>ma;
    
    void update_pq(priority_queue<pair<int,string>,vector<pair<int,string>>,comp>&pq,pair<int,string>&curr){
        vector<pair<int,string>>vec;
        bool ispresent = 0;
        while(!pq.empty()){
            vec.push_back(pq.top());
            if(curr.second == vec.back().second){
                vec.pop_back();
                vec.push_back(curr);
                ispresent = 1;
            }
            pq.pop();
        }
        if(!ispresent){
            vec.push_back(curr);
        }
        while(!vec.empty()){
            pq.push(vec.back());
            vec.pop_back();
        }
        if(pq.size() > 3){
            pq.pop();
        }
        return;
    }
    
    void add(string s,int t){
        pair<int,string> curr = {t,s};
        string curr_prefix = "";
        for(int j = 0; j < s.length(); j++){
            curr_prefix += s[j];
            update_pq(ma[curr_prefix],curr);
        }
        return;
    }
    
    AutocompleteSystem(vector<string>& s, vector<int>& t) {
        ma.clear();
        prefix = "";
        for(int i = 0; i < s.size(); i++){
            search_freq[s[i]] = t[i];
            add(s[i],t[i]);
        }
    }
    
    vector<string> input(char c) {
        if(c == '#'){
            search_freq[prefix] = search_freq[prefix] + 1;
            add(prefix,search_freq[prefix]);
            prefix = "";
            return {};
        }
        prefix += c;
        if(ma[prefix].empty()){
            return {};
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> aux = ma[prefix];
        vector<string> ans(aux.size());
        int idx = aux.size() - 1;
        while(!aux.empty()){
            ans[idx--] = aux.top().second;
            aux.pop();
        }
        return ans;
    }
};