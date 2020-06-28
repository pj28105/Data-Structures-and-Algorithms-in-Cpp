#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/intersection-of-two-linked-lists/
    
    Tested on Leetcode!
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        if(!l1 or !l2){
            return NULL;
        }
        // Checking if intersection point exists
        ListNode* c1 = l1,*c2 = l2;
        while(c1->next){
            c1 = c1->next;
        }
        while(c2->next){
            c2 = c2->next;
        }
        // Lists dosen't intersect
        if(c1 != c2){
            return NULL;
        }
        c1 = l1,c2 = l2;
        while(1){
            if(c1 == c2){
                return c1;
            }
            c1 = c1->next;
            c2 = c2->next;
            if(!c1){
                c1 = l2;
            }
            if(!c2){
                c2 = l1;
            }
        }
        return NULL;
    }
};