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
            
        Or
            Go to github for optimal solution!
    Tested on Leetcode!
*/

struct comp{    
    bool operator()(const ListNode* a,const ListNode* b) const{
        return a->val >= b->val;
    }   
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& a) {
       int n = a.size();
       priority_queue<ListNode*,vector<ListNode*>,comp>q;
       for(int i = 0; i < n; i++){
           if(a[i]){
               q.push(a[i]);
           }
       }
       ListNode* dummy = new ListNode(-1);
       ListNode* curr = dummy;
       while(!q.empty()){
           ListNode* best = q.top();
           q.pop();
           curr->next = best;
           curr = best;
           if(best->next){
               q.push(best->next);
           }
       }
       return dummy->next;
    }
};