/*
    Problem link -:
        https://leetcode.com/problems/alien-dictionary/
    
    Tested on Leetcode

    Notes-:
        1) Do checkout its editorial for understanding multiple corner cases
*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<char, int> indegree;
        
        // Below pre-processing will solve many corner cases
        for(string s : words){
            for(char c : s){
                indegree[c] = 0;
            }
        }
        for(int i = 1; i < words.size(); i++){
            string currWord = words[i];
            string prevWord = words[i - 1];
            
            if(prevWord.length() > currWord.length() && 
                        prevWord.substr(0, currWord.length()) == currWord){
                return "";
            }
            int minLength = min(currWord.length(), prevWord.length());
            for(int j = 0; j < minLength; j++){
                if(currWord[j] != prevWord[j]){
                    if(!graph[prevWord[j]].count(currWord[j])){
                        graph[prevWord[j]].insert(currWord[j]);
                        indegree[currWord[j]]++;
                    }    
                    break;
                }
            }
        }
        queue<char> q;
        for(auto &entry : indegree){
            if(entry.second == 0){
                q.push(entry.first);
            }
        }
        string res = "";
        while(!q.empty()){
            char currChar = q.front();
            q.pop();
            res += currChar;
            for(char c : graph[currChar]){
                indegree[c]--;
                if(indegree[c] == 0){
                    q.push(c);
                }
            }
        }
        if(res.size() < indegree.size()) {
            return "";
        }
        return res;
    }
};