/*
    Problem link->
        https://leetcode.com/problems/largest-submatrix-with-rearrangements/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>look;
        int n = mat.size(),m = mat[0].size();
        int cnt[n][m];
        memset(cnt,0,sizeof(cnt));
        for(int i = 0; i < m; i++){
            for(int j = n - 1; j >= 0; j--){
                if(j == n - 1){
                    cnt[j][i] = mat[j][i];
                }else if(mat[j][i] == 1){
                    cnt[j][i] = 1 + cnt[j + 1][i];
                }
                look[j].push_back(cnt[j][i]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            sort(look[i].begin(),look[i].end());
            int size = look[i].size();
            for(int j = 0; j < size; j++){
                if(look[i][j] > 0){
                    ans = max(ans,look[i][j] * (size - j));
                }
            }
        }
        return ans;
    }
};