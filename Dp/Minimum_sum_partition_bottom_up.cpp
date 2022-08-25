/*
    Problem link-:

    https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

    Tested on GFG
*/

signed main(void)
{
    tc{
        int n,sum = 0;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        bool dp[2][sum + 1];
        memset(dp,0,sizeof(dp));
        dp[1][0] = 1;
        for(int i = 0; i < n; i++){
            int currRow = i & 1;
            for(int j = 0; j < a[i]; j++){
                dp[currRow][j] = dp[currRow ^ 1][j];
            }
            for(int j = a[i]; j <= sum; j++){
                dp[currRow][j] = dp[currRow ^ 1][j] || dp[currRow ^ 1][j - a[i]];
            }
        }
        int ans = 0;
        for(int j = sum/2; j >= 0; j--){
            if(dp[(n - 1) & 1][j]){
                ans = abs((sum - j) - j);
                break;
            }
        }
        cout << ans << endl;
    }      
    return 0;
}