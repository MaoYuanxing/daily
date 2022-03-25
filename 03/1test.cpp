#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution1
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if (words.size() == 0 || s.size() == 0)
            return {};
        vector<int> res;
        unordered_map<string, int> words_map;
        for (string s : words)
        {
            words_map[s]++;
        }
        int w = words[0].size();
        int len = w * words.size();
        unordered_map<string, int> tmp_map;
        for (int start = 0; start + len <= s.size(); start++)
        {
            tmp_map.clear();
            int j = 0;
            for (; j < len; j += w)
            {
                string tmp = s.substr(start + j, w);
                if (words_map[tmp])
                {
                    tmp_map[tmp]++;
                    if (tmp_map[tmp] > words_map[tmp])
                        break;
                }
                else
                    break;
            }
            if (j == len)
            {
                res.push_back(start);
            }
        }
        return res;
    }
};

class Solution2
{
public:
    int longestValidParentheses(string s)
    {
        int maxans = 0, n = s.length(), len = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                    len = 0;
                }
                else
                {
                    len += i - st.top();
                    maxans = max(len, maxans);
                }
            }
            else
                st.push(i);
        }

        return maxans;
    }
};

class Solution3
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        stack<int> s;
        int temp;
        for (int i = 0; i < height.size(); i++)
        {
            if (s.empty())
            {
                s.push(i);
            }
            else
            {
                int j = s.top();
                if (height[j] > height[i])
                    s.push(i);
                else
                {
                    while (height[j] <= height[i])
                    {
                        s.pop();
                        if (s.empty())
                        {
                            s.push(i);
                            break;
                        }
                        temp = j;
                        j = s.top();
                        ans += (height[j] - height[temp]) * (i - j - 1);
                    }
                    if (height[i] < height[s.top()])
                        s.push(i);
                }
            }
        }
        return ans;
    }
};

class Solution4
{
    string addStrings(string num1, string num2)
    {
        if (num1 == "0")
            return num2;
        if (num2 == "0")
            return num1;
        int n1 = num1.size() - 1, n2 = num2.size() - 1;
        string res;
        int carry = 0;
        while (n1 >= 0 || n2 >= 0)
        {
            int i = n1 < 0 ? 0 : num1[n1] - '0';
            int j = n2 < 0 ? 0 : num2[n2] - '0';
            int sum = (i + j + carry) % 10;
            carry = (i + j + carry) / 10;
            res += sum + '0';
            n1--;
            n2--;
        }
        if (carry)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }

public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        string res = "0";
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            string tmp;
            int n1 = num1[i] - '0';
            int j = 0;
            for (int k = num2.size() - 1; k >= 0; k--)
            {
                int n2 = num2[k] - '0';
                int mul = (n1 * n2 + j) % 10;
                j = (n1 * n2 + j) / 10;
                tmp += mul + '0';
            }
            if (j)
                tmp += j + '0';
            reverse(tmp.begin(), tmp.end());
            if (i > 0)
            {
                int ii = i;
                while (ii)
                {
                    tmp += '0';
                    ii--;
                }
            }
            res = addStrings(res, tmp);
        }
        return res;
    }
};

class Solution5
{
public:
    bool isMatch(string s, string p)
    {
        if (s.size() == 0 ^ p.size() == 0)
        {
            if (p[0] == '*')
                return isMatch(s, p.substr(1));
            ;
            return false;
        }
        if (s.size() == 0 && p.size() == 0)
            return true;
        bool firstmatch = s[0] == p[0] || p[0] == '*' || p[0] == '?';
        if (p[0] == '*')
        {
            return isMatch(s.substr(1), p) || isMatch(s.substr(1), p.substr(1)) || isMatch(s, p.substr(1));
        }
        else
        {
            return firstmatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

class Solution
{
    bool firstmatch(string s, string p, int i, int j)
    {
        return s[i] == p[j] || p[j] == '?' || p[j] == '*';
    }

public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, 0));
        dp[0][0] = true;
        for (int j = 1; j < p.size() + 1; j++)
        {
            dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
        }
        for (int i = 1; i < s.size() + 1; i++)
        {
            dp[i][0] = false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < p.size(); j++)
            {
                if (p[j] == '*')
                {
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i][j] || dp[i + 1][j];
                }
                else
                {
                    dp[i + 1][j + 1] = firstmatch(s, p, i, j) && dp[i][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
int main()
{
    Solution a;
    string num1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", num2 = "*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*";
    cout << a.isMatch(num1, num2);
    return 0;
}