int longest_increasing_subsequence(const vi &arr)
{
    vi ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        // lower_bound for increasing subsequence
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
        // upper_bound for non deacreasing subsequence
        // auto it = upper_bound(ans.begin(), ans.end(), arr[i]);
        if (it == ans.end())
            ans.push_back(arr[i]);
        else
            *it = arr[i];
    }
    return ans.size();
}
