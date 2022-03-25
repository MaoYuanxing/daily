#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
        return 0;
    int res = 1;
    int left = 0, right = 1;
    int a[27] = {0};
    while (right < s.size())
    {
        if (a[s[right] - 'a'])
        {
            res = res > right - left ? res : right - left;
            while (s[left] != s[right])
            {
                char c = s[left];
                a[c - 'a'] = 0;
                left++;
            }
            left++;
            continue;
        }
        right++;
        char c1 = s[right];
        a[c1 - 'a'] = 1;
    }
    return res;
}
int myAtoi(string s)
{
    queue<int> sa;
    bool flag = 0;
    int sign = 1;
    for (char c : s)
    {
        if (sa.empty())
        {
            if (c == '-' || c == '+')
            {
                flag = 1;
                sa.push(c == '-' ? -1 : 1);
            }
            else if (c <= '9' && c >= '0')
            {
                sa.push(c - '0');
            }
            else if (c == ' ')
                continue;
            else
                break;
        }
        else
        {
            if (c <= '9' && c >= '0')
            {
                sa.push(c - '0');
            }
            else
                break;
        }
    }

    if (sa.empty() || (flag && sa.size() == 1))
        return 0;
    if (flag)
    {
        sign *= sa.front();
        sa.pop();
    }
    int ans = 0;
    while (!sa.empty())
    {
        int i = sa.front();
        cout << i << " ";
        sa.pop();
        if (sign > 0 && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && i > 7)))
        {
            return INT_MAX;
        }
        if (sign < 0 && (-ans < INT_MIN / 10 || (-ans == INT_MIN / 10 && -i < -8)))
        {
            return INT_MIN;
        }
        ans = ans * 10 + i;
    }

    return ans;
}

void print(vector<vector<string>> &map)
{
    cout << endl;
    for (auto S : map)
    {

        for (auto s : S)
        {
            cout << s << ", ";
        }
        cout << endl;
    }
    cout << endl;
}
string muti(string s, int j)
{
    if (j < 0)
        return {};
    string ans = s;
    while (j)
    {
        ans += s;
        j--;
    }
    return ans;
}
class Solution
{
    vector<string> numsPad()
    {
        vector<string> res;
        res.push_back("");
        res.push_back("");
        res.push_back("abc");
        res.push_back("def");
        res.push_back("ghi");
        res.push_back("jkl");
        res.push_back("mno");
        res.push_back("pqrs");
        res.push_back("tuv");
        res.push_back("wxyz");
        return res;
    }

    void solver(vector<string> &ans, vector<string> &numsPad, string &digits)
    {
        if (digits == "")
        {
            ans.push_back("");
            return;
        }
        int cur = digits[0] - '0';
        digits.erase(0, 1);
        vector<string> particalAnster;
        solver(particalAnster, numsPad, digits);
        for (auto CurString : numsPad[cur])
        {
            for (auto pre : particalAnster)
            {
                ans.push_back(CurString + pre);
            }
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        vector<string> nums = numsPad();
        solver(ans, nums, digits);
        return ans;
    }
};

class Solution1
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    if (nums[l] + nums[r] > target - nums[i] - nums[j])
                        r--;
                    else if (nums[l] + nums[r] < target - nums[i] - nums[j])
                        l++;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                }
            }
        }
        return ans;
    }
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution2
{
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
            return 0;
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            else
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if (l1)
            tmp->next = l1;
        if (l2)
            tmp->next = l2;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }

    ListNode *Merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int m = l + ((r - l) >> 1);
        return merge(Merge(lists, l, m), Merge(lists, m + 1, r));
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (!lists.size())
            return nullptr;

        struct cmp
        {
            bool operator()(ListNode *a, ListNode *b)
            {
                return a->val > b->val;
            }
        };

        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto node : lists)
        {
            ListNode *i = node;
            while (i)
            {
                pq.push(i);
                i = i->next;
            }
        }
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy;
        vector<int> pp;
        while (!pq.empty())
        {
            tmp->next = pq.top();
            tmp = tmp->next;
            pp.push_back(tmp->val);
            pq.pop();
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

class Solution3
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        int i = 0;
        for (int j = 1; j < n; j++)
        {
            while (nums[j] == nums[j - 1])
            {
                j++;
                if (j == n)
                    return i + 1;
            }
            nums[++i] = nums[j];
        }
        return i;
    }
};
int main()
{
    Solution3 a;
    vector<int> nums = {1, 1, 2};
    a.removeDuplicates(nums);
    return 0;
}
