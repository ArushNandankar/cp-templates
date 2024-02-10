// knapSack with O(nW) Time complexity and O(W) Space complexity
// returns the maximum value you can get
int knapSack(int W, const vi &wt, const vi &val)
{
    int n = wt.size();
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++)
    {
        for (int w = W; w >= 0; w--)
        {
            if (wt[i - 1] <= w)
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

// knapSack with O(nW) Time complexity and O(nW) Space complexity
// fills boolean array pickedItems with true for items that
// were picked by the algorithm
void _knapsack(int W, const vi &wt, const vi &val, vector<bool> &pickedItems)
{
    int n = wt.size();
    vvi dp(n + 1, vi(W + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    // Backtrack to find which items were picked
    int i = n, w = W;
    while (i > 0 && w > 0)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            pickedItems[i - 1] = true;
            w -= wt[i - 1];
        }
        --i;
    }
}