#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3073/
    
    Tested on Leetcode!
*/
class Solution
{
public:
     string rep(string& aux, int freq)
    {
        freq--;
        string temp = aux;
        while (freq > 0)
        {
            aux += temp;
            freq--;
        }
        return aux;
    }
    string decodeString(string s){
        if (s.empty())
        {
            return "";
        }
        stack<string>st;
        string ans = "";
        for(auto i : s){
            if(i == ']'){
                string currString = "";
                while(st.top() != "["){
                    currString = st.top() + currString;
                    st.pop();
                }
                st.pop();
                string freq = "";
                while(!st.empty() && st.top()[0] >= '0' && st.top()[0] <= '9'){
                    freq = st.top() + freq;
                    st.pop();
                }
                st.push(rep(currString,stoi(freq)));
            }else{
                string aux = "";
                aux += i;
                st.push(aux);
            }
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};