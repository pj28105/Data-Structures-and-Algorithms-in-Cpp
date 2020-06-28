#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/merge-k-sorted-lists
    
    Time-> O(NlogK)
    Space-> O(1)
    
    1) This problems has several solutions check them on github!
    
    Tested on Leetcode!
*/

class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b){
        if(!a || !b){
            return a == NULL ? b : a;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(a && b){
            if(a->val <= b->val){
                curr->next = a;
                curr = a;
                a = a->next;
            }else{
                curr->next = b;
                curr = b;
                b = b->next;
            }
        }
        if(!b){
            curr->next = a;
        }else{
            curr->next = b;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& a) {
        if(a.empty()){
            return NULL;
        }       
        int n = a.size();
        int e = n - 1;
        while(e != 0){
            int i = 0,j = e;
            while(i < j){
                a[i] = merge(a[i],a[j]);
                i++;
                j--;
                if(i >= j){
                    e = j;
                }
            }
        }
        return a[0];
    }
};