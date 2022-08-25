/*
    Problem link-:

    https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

    Tested on GFG
*/

int dp[100][3000];

int solv(int a[],int i,int n,int sum,int total){
    if(i >= n){
        return abs(sum - (total - sum));
    }
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    int ans = min(solv(a,i + 1,n,sum - a[i],total),solv(a,i + 1,n,sum,total));
    dp[i][sum] = ans;
    return ans;
}

signed main(void)
{
    ios;
    #ifndef ONLINE_JUDGE
      //  freopen("../in.txt","r",stdin);
    #endif
    tc{
        int n,sum = 0;
        cin >> n;
        int a[n];
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        cout << solv(a,0,n,sum,sum) << endl;
    }      
    return 0;
}