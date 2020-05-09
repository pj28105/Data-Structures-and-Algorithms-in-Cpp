#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

    This is dp version of this problem.
    But use bfs appraoch this approach is little tricky!

    Note-> For memoization logic look at comments in code!

    Tested on GFG and Leetcode.
*/

const int inf = INT_MAX;
bool vis[200][200];
int solv(vector<vector<int> >&a,int i,int j,vector<vector<int> >&time,int currAns){
    if(i < 0 || j < 0 || i >= a.size() || j >= a[0].size()){
        return inf;
    }
    if(a[i][j] == 0 || vis[i][j])
        return inf;
    if(a[i][j] == 2){
        return currAns;
    }
    if(time[i][j] != inf){
        return time[i][j] + currAns;
    }
    vis[i][j] = 1;
    int ans = solv(a,i + 1,j,time,currAns + 1);
    ans = min(ans,solv(a,i,j + 1,time,currAns + 1));
    ans = min(ans,solv(a,i - 1,j,time,currAns + 1));
    ans = min(ans,solv(a,i,j - 1,time,currAns + 1));
    vis[i][j] = 0;
    /*
        Don't memoize time[i][j] here
        Answer for all cells you are visiting from source cell may not be optimal.
        But final answer for source cell would be optimal.(check notebook)
    */
    return ans;
}

int rotOranges(vector<vector<int> > a, int r, int c){
    vector<vector<int>> time(r,vector<int>(c,inf));
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] == 1 && time[i][j] == inf){
                /*
                    Answer is optimal you can memoize it for future use
                */
                time[i][j] = solv(a,i,j,time,0);
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] == 1){
                ans = max(ans,time[i][j]);
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
}