#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/merge-k-sorted-lists
    
    Time-> O(NlogK)
    Space-> O(K)
    
    1) This can be solved in O(N*K) time and O(1) space! checkout github
    2) This problem has anothen approach which solves this problem in O(NlogN) time and O(1) space
        Solution link->
            https://leetcode.com/problems/merge-k-sorted-lists/solution/

    Tested on Leetcode!
*/

struct comp{    
    bool operator()(const pair<int,ListNode*> a,const pair<int,ListNode*> b) const{
        return a.first >= b.first;
    }   
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& a) {
       int n = a.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,comp>q;
       for(int i = 0; i < n; i++){
           if(a[i]){
               q.push({a[i]->val,a[i]});
           }
       }
       ListNode* dummy = new ListNode(-1);
       ListNode* curr = dummy;
       while(!q.empty()){
           pair<int,ListNode*> best = q.top();
           q.pop();
           curr->next = best.second;
           curr = best.second;
           if(best.second->next){
               q.push({best.second->next->val,best.second->next});
           }
       }
       return dummy->next;
    }
};