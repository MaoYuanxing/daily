#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lengthOfLIS(vector<long long> &nums)
{
    int n = (int)nums.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int ans(vector<pair<long long, long long>> &x)
{
    int res = 1;
    sort(x.begin(), x.end());
    vector<long long> a(x.size());
    for (int i = 0; i < x.size(); i++)
    {
        a[i] = x[i].second;
    }
    res = lengthOfLIS(a);
    return res;
}

int main()
{
    int T;
    cin >> T;
    int n[T];
    vector<vector<pair<long long, long long>>> x(T);
    for (int i = 0; i < T; i++)
    {
        cin >> n[i];
        x[i].resize(n[i]) for (int j = 0; j < n[i]; j++)
        {
            cin >> x[i][j].first;
        }
        for (int j = 0; j < n[i]; j++)
        {
            cin >> x[i][j].second;
        }
    }
    for (int i = 0; i < T; i++)
    {
        cout << ans(x[i]) << endl;
    }

    return 0;
}