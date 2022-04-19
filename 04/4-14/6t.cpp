#include <bits/stdc++.h>
using namespace std;

vector<int> help(int n, int k, int x)
{
    if (n > k || n * (k * 2 - n + 1) < 2 * x || n * (n + 1) > 2 * x)
        return {};
    vector<int> ans(n);
    for (int i = 1; i <= n; i++)
        ans[i - 1] = i;
    if (n * (n + 1) == 2 * x)
    {
        return ans;
    }
    if (n * (k * 2 - n + 1) == 2 * x)
    {
        for (int i = 0; i <= n; i++)
            ans[i] += k - n;
        return ans;
    }

    int dif = x - n * (n + 1) / 2;
    int i = dif / n;
    if (i == 0)
    {
        int j = dif % n;
        for (int kk = j, l = n - 1; kk >= 0; kk--, l--)
        {
            ans[l]++;
        }
    }
    else
    {
        for (int kk = 0; kk < n; kk++)
        {
            ans[kk] += i;
        }
        int j = dif % n;
        for (int kk = j, l = n - 1; kk > 0; kk--, l--)
        {
            ans[l]++;
        }
    }
    return ans;
}

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> ans = help(n, k, x);
    if (ans.size() == 0)
        cout << -1;
    else
    {
        for (int i : ans)
        {
            cout << i << " ";
        }
    }
}