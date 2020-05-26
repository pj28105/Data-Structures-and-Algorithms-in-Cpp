#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/find-median-from-data-stream/
    
    Tested on Leetcode!
*/
class MedianFinder {
public:
    priority_queue<int>lo;
    priority_queue<int,vector<int>,greater<int>>hi;
    
    MedianFinder() {
        while(!lo.empty()){
            lo.pop();
        }    
        while(!hi.empty()){
            hi.pop();
        }    
    }
    
    void addNum(int num){
      lo.push(num);
      hi.push(lo.top());
      lo.pop();
      if(hi.size() > lo.size()){
          lo.push(hi.top());
          hi.pop();
      }
    }
    
    double findMedian() {
        if(lo.size() == hi.size()){
            return (lo.top() + hi.top())/2.0;
        }
        return lo.top();
    }
};