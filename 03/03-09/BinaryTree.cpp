#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
vector<int> in = {4, 2, 5, 1, 6, 3, 7};
unordered_map<int, int> hashtable;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val = 0) : val(val), left(nullptr), right(nullptr)
    {
    }
};

void reverse(TreeNode *head)
{
    if (head == nullptr)
    {
        return;
    }
    // 1
    cout << head->val;
    reverse(head->left);
    // 2
    // cout << head->val;
    reverse(head->right);
    // cout << head->val;
    //  3
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr ^ q == nullptr)
    {
        return false;
    }
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    //都不为空
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool isMirror(TreeNode *h1, TreeNode *h2);
bool isSymmetric(TreeNode *root)
{
    return isMirror(root, root);
}

bool isMirror(TreeNode *h1, TreeNode *h2)
{
    if (h1 == nullptr ^ h2 == nullptr)
    {
        return false;
    }
    if (h1 == nullptr && h2 == nullptr)
    {
        return true;
    }
    return h1->val == h2->val && isMirror(h1->left, h2->right) && isMirror(h1->right, h2->left);
}

int TreeHeight(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return max(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}
TreeNode *helper(const vector<int> &pre, int L1, int R1, const vector<int> &in, int L2, int R2);
TreeNode *bulidTree(const vector<int> &pre, const vector<int> &in)
{
    int n1 = pre.size(), n2 = in.size();
    if (n1 == 0 || n2 == 0 || n1 != n2)
    {
        return nullptr;
    }
    return helper(pre, 0, n1 - 1, in, 0, n2 - 1);
}

TreeNode *helper(const vector<int> &pre, int L1, int R1, const vector<int> &in, int L2, int R2)
{
    if (L1 > R1)
    {
        return nullptr;
    }
    int rootIndex = hashtable[pre[L1]];
    TreeNode *root = new TreeNode(pre[L1]);
    root->left = helper(pre, L1 + 1, rootIndex - L2 + L1, in, L2, rootIndex - 1);
    root->right = helper(pre, rootIndex - L2 + L1 + 1, R1, in, rootIndex + 1, R2);
    return root;
}

int main()
{
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    // reverse(head);
    cout << endl;
    TreeNode *head1 = new TreeNode(1);
    head1->left = new TreeNode(3);
    head1->right = new TreeNode(2);
    TreeNode *root = new TreeNode(0);
    root->left = head1;
    root->right = head;
    if (isSymmetric(root))
    {
        cout << "是镜面的树" << endl;
    }
    else
    {
        cout << "不是镜面的树" << endl;
    }
    cout << "root height: " << TreeHeight(root) << endl;

    int count = 0;
    for (int i : in)
    {
        hashtable[i] = count++;
    }
    reverse(bulidTree(pre, in));
    cout << endl;
    return 0;
}