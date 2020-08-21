#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/my-calendar-ii/
    
    Tested on Leetcode!
*/
class MyCalendarTwo {
public:
    vector<pair<int,int>>inter;
    vector<pair<int,int>>overlap;
    MyCalendarTwo() {
        inter.clear();
        overlap.clear();
    }
    
    bool book(int start, int end) {
        end--;  
        for(auto i : overlap){
          if(!(end < i.first || i.second < start)){
                return 0;      
          }
         }
         for(auto i : inter){
           if(!(end < i.first || i.second < start)){
                int new_start = max(i.first,start);
                int new_end = min(i.second,end);
                overlap.push_back({new_start,new_end});
            }  
         }
        inter.push_back({start,end});
        return 1;
    }
};
