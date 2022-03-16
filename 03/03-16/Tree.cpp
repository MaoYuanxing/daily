#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(0), right(0) {}
};

void preOrder(TreeNode *head)
{
    if (head == nullptr)
        return;
    stack<TreeNode *> s;
    s.push(head);
    while (!s.empty())
    {
        TreeNode *tmp = s.top();
        cout << tmp->val << ", ";
        s.pop();
        if (tmp->right)
            s.push(tmp->right);
        if (tmp->left)
            s.push(tmp->left);
    }
    cout << endl;
}
void postOrder(TreeNode *head)
{
    if (head == nullptr)
        return;
    stack<TreeNode *> s;
    stack<TreeNode *> sa;
    sa.push(head);
    while (!sa.empty())
    {
        TreeNode *tmp = sa.top();
        s.push(tmp);
        sa.pop();
        if (tmp->left)
            sa.push(tmp->left);
        if (tmp->right)
            sa.push(tmp->right);
    }
    while (!s.empty())
    {
        cout << s.top()->val << ", ";
        s.pop();
    }
    cout << endl;
}
void inOrder(TreeNode *head)
{
    if (head == nullptr)
        return;
    stack<TreeNode *> s;
    while (!s.empty() || head)
    {
        if (head)
        {
            s.push(head);
            head = head->left;
        }
        else
        {
            head = s.top();
            cout << head->val << ", ";
            s.pop();
            head = head->right;
        }
    }
    cout << endl;
}

int maxWidthbyhash(TreeNode *head)
{
    if (head == nullptr)
        return 0;
    unordered_map<TreeNode *, int> Hash;
    Hash[head] = 1;
    int curLevel = 1;
    int curLevelNodes = 0;
    int max = -1;
    queue<TreeNode *> q;
    q.push(head);
    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();
        int curNodeLevel = Hash[cur];
        if (curNodeLevel == curLevel)
        {
            curLevelNodes++;
        }
        else
        {
            max = max < curLevelNodes ? curLevelNodes : max;
            curLevel++;
            curLevelNodes = 1;
        }
        if (cur->left)
        {
            q.push(cur->left);
            Hash[cur->left] = curNodeLevel + 1;
        }
        if (cur->right)
        {
            q.push(cur->right);
            Hash[cur->right] = curNodeLevel + 1;
        }
    }
    max = max < curLevelNodes ? curLevelNodes : max;
    return max;
}

int NohashmaxWidth(TreeNode *head)
{
    TreeNode *curend = head;
    TreeNode *nextend = 0;
    queue<TreeNode *> q;
    q.push(head);
    int max = -1;
    int curNodes = 0;
    while (!q.empty())
    {
        TreeNode *cur = q.front();
        curNodes++;
        q.pop();
        if (cur->left)
        {
            q.push(cur->left);
            nextend = cur->left;
        }
        if (cur->right)
        {
            q.push(cur->right);
            nextend = cur->right;
        }
        if (cur == curend)
        {
            max = max < curNodes ? curNodes : max;
            curend = nextend;
            curNodes = 0;
        }
    }
    return max;
}
int main()
{
    unordered_map<TreeNode *, int> Hash;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->right->left = new TreeNode(6);
    head->left->right = new TreeNode(5);
    head->right->right = new TreeNode(7);
    cout << NohashmaxWidth(head) << endl;
    preOrder(head);
    postOrder(head);
    inOrder(head);
    return 0;
}
