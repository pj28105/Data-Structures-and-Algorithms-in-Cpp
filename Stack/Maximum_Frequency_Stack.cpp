#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/amazon/81/design/3001/
    
    Tested on Leetcode!
*/
class FreqStack {
public:
    unordered_map<int,int>freq;
    vector<stack<int>>st;
    int maxFreq;
    FreqStack() {
        st.clear();
        st.push_back(stack<int>());
        freq.clear();
        maxFreq = 0;
    }
    
    void push(int x) {
        freq[x]++;
        if(st.size() == freq[x]){
            st.push_back(stack<int>());
            maxFreq = freq[x];
        }
        st[freq[x]].push(x);
        return;
    }
    
    int pop() {
        int result = st[maxFreq].top();
        st[maxFreq].pop();
        freq[result]--;
        if(st[maxFreq].empty()){
            maxFreq--;
            st.pop_back();
        }
        return result;
    }
};