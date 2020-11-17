/*      
    Problem link-> 
        https://leetcode.com/problems/guess-the-word/
    
    Tested on Leetcode!
    
    Google TOP 50 leetcode question!

    This solution is inspired from
        https://leetcode.com/problems/guess-the-word/discuss/133862/Random-Guess-and-Minimax-Guess-with-Comparison
*/  
class Solution {
public:
    int getMatchCount(string& a,string& b){
        int cnt = 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] == b[i]){
                cnt++;
            }
        }
        return cnt;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while(1){
            // select word with least zero max count
            unordered_map<string,int>ma;
            for(string &i : wordlist){
                for(string &j : wordlist){
                    if(getMatchCount(i,j) == 0){
                        ma[i]++;
                    }
                }
            }
            pair<string,int> best = {"",INT_MAX};
            for(auto &i : wordlist){
                if(ma[i] < best.second){
                    best.second = ma[i];
                    best.first = i;
                }
            }
            string curr = best.first;
            int match_cnt = master.guess(curr);
            if(match_cnt == 6){
                return;
            }
            vector<string> aux;
            for(int i = 0; i < wordlist.size(); i++){
                if(getMatchCount(best.first,wordlist[i]) == match_cnt){
                    aux.push_back(wordlist[i]);
                }
            }
            wordlist = aux;
        }
        return;
    }
};