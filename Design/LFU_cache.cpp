#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/lfu-cache/

    Tested on Leetcode!
*/
class LinkedList{
    public:
        LinkedList* prev,*next;
        int key,value;

        LinkedList(int key = -1,int value = -1){
            this->key = key;
            this->value = value;
            prev = NULL,next = NULL;
        }

        LinkedList* insert(LinkedList* &head,LinkedList* &tail,int key,int value){
            if(!head){
                head = new LinkedList(key,value);
                tail = head;
                return head;
            }
            LinkedList* node = new LinkedList(key,value);
            node->next = head;
            head->prev = node;
            head = node;
            return node;
        }
    
        pair<int,int> del(LinkedList* node,LinkedList* &head,LinkedList* &tail){
            int key = node->key,value = node->value;
            if(tail == node){
                return del_lru(head,tail);
            }
            if(head == node){
                head = head->next;
                head->prev = NULL;
                delete node;
                return {key,value};
            }
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            return {key,value};
        }
        
        pair<int,int> del_lru(LinkedList* &head,LinkedList* &tail){
            if(head == tail){
                int key = head->key,value = head->value;
                delete head;
                head = NULL,tail = NULL;
                return {key,value};
            }
            int key = tail->key,value = tail->value;
            LinkedList *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            return {key,value};
        }
};

class Bucket{
    public:
        unordered_map<int,LinkedList*>l_ref;
        static Bucket* b_head,*b_tail;
        int b_no;
        Bucket* prev,*next;
        LinkedList* head,*tail;
        LinkedList control;
    
        Bucket(int b_no = -1){
            this->b_no = b_no;
            this->prev = this->next = NULL;
            head = NULL,tail = NULL;
        }
        
        Bucket* insert(Bucket* buck,int key,int value){
            if(!buck){
                if(!b_head || b_head->b_no != 1){
                    Bucket* node = new Bucket(1);
                    if(b_head){
                        b_head->prev = node;
                        node->next = b_head;
                    }else{
                        b_tail = node;   
                    }
                    b_head = node;
                    node->l_ref[key] = node->control.insert(node->head,node->tail,key,value);
                    return node;
                }else{
                    b_head->l_ref[key] = b_head->control.insert(b_head->head,b_head->tail,key,value);
                    return b_head;
                }
            }
            buck->l_ref[key] = buck->control.insert(buck->head,buck->tail,key,value);
            return buck;
        }
    
        void del(Bucket* curr){
            if(b_head == curr){
                if(b_head == b_tail){
                    b_head = b_tail = NULL;
                    delete curr;
                    return;
                }
                b_head = b_head->next;
                b_head->prev = NULL;
                delete curr;
                return;
            }
            if(b_tail == curr){
                b_tail = b_tail->prev;
                b_tail->next = NULL;
                delete curr;
                return;
            }
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            delete curr;
            return;
        }
    
        int del_lfu(){
            int key = b_head->control.del_lru(b_head->head,b_head->tail).first;
            b_head->l_ref.erase(key);
            if(b_head->l_ref.size() == 0){
                del(b_head);
            }
            return key;
        }
    
        Bucket* increment(Bucket* curr,int key){
            pair<int,int> k_v = curr->control.del(curr->l_ref[key],curr->head,curr->tail);
            curr->l_ref.erase(key);
            if(!curr->next || curr->next->b_no != curr->b_no + 1){
                Bucket* node = new Bucket(curr->b_no + 1);
                if(curr->next){
                    curr->next->prev = node;
                }else{
                    b_tail = node;
                }
                node->next = curr->next;
                curr->next = node;
                node->prev = curr;
            }
            Bucket* temp = insert(curr->next,k_v.first,k_v.second);;
            if(curr->l_ref.size() == 0){
                del(curr);
            }
            return temp;    
        }
};

Bucket* Bucket::b_head = NULL;
Bucket* Bucket::b_tail = NULL;

class LFUCache {
public:
    bool invalid = 0;
    int size;
    int currsize = 0;
    unordered_map<int,Bucket*>b_ref;
    Bucket control;
    
    LFUCache(int capacity) {
        invalid = 0;
        if(capacity <= 0){
            invalid = 1;
            size = 1;
        }else{
            size = capacity;
        }
        b_ref.clear();
        currsize = 0;
        Bucket::b_head = NULL;
        Bucket::b_tail = NULL;
    }
    
    int get(int key) {
        if(invalid){
            return -1;
        }
        if(b_ref.find(key) == b_ref.end()){
            return -1;
        }
        int value = b_ref[key]->l_ref[key]->value;
        b_ref[key] = control.increment(b_ref[key],key);
        return value;
    }
    
    void put(int key, int value) {
        if(invalid){
            return;
        }
        if(b_ref.find(key) == b_ref.end()){
            if(size < (currsize + 1)){
                int key = control.del_lfu();
                b_ref.erase(key);
                currsize--;
            }
            Bucket* buck = control.insert(NULL,key,value);
            b_ref[key] = buck;
            currsize++;
            return;
        }
        b_ref[key]->l_ref[key]->value = value;
        b_ref[key] = control.increment(b_ref[key],key);
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */