/*
    Problem link->
        https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
       unordered_map<int,int>look;
        for(int i = 0; i < target.size(); i++){
            look[target[i]] = i;
        }
        vector<int>lis;
        for(int i : arr){
            if(look.count(i)){
                if((lis.empty()) || lis.back() < look[i]){
                    lis.push_back(look[i]);
                }else{
                    int index = lower_bound(lis.begin(),lis.end(),look[i]) - lis.begin();
                    lis[index] = look[i];
                }
            }
        }
        return target.size() - lis.size();
    }
};