#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val = 0) : val(val), next(nullptr) {}
};

struct DLLNode
{
    int val;
    DLLNode *pre;
    DLLNode *next;

    DLLNode(int val = 0) : val(val), pre(nullptr), next(nullptr) {}
};

ListNode *reverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *next = nullptr;
    while (cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode *rreverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *newHead = rreverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

ListNode *evilreverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *cur = head;
    while (head->next != NULL)
    {
        ListNode *t = head->next->next;
        head->next->next = cur;
        cur = head->next;
        head->next = t;
    }
    return cur;
}

DLLNode *Dreverse(DLLNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    DLLNode *pre = nullptr;
    while (head)
    {
        head->pre = head->next;
        head->next = pre;
        pre = head;
        head = head->pre;
    }
    return pre;
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << ", ";
        temp = temp->next;
    }
    cout << endl;
}

void Dprint(DLLNode *head)
{
    while (1)
    {
        cout << head->val << ", ";
        if (!head->next)
            break;
        head = head->next;
    }
    cout << endl;
    while (head)
    {
        cout << head->val << ", ";
        head = head->pre;
    }
    cout << endl;
}

ListNode *deleteValue(ListNode *head, int key)
{
    while (head != nullptr)
    {
        if (head->val != key)
            break;
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    if (head)
    {
        ListNode *cur = head->next;
        ListNode *pre = head;
        while (cur)
        {
            if (cur->val == key)
            {
                ListNode *temp = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete temp;
                continue;
            }
            cur = cur->next;
            pre = pre->next;
        }
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    print(head);
    print(deleteValue(head, 1));
    DLLNode *root = new DLLNode(2);
    // root->next = new DLLNode(4);
    // root->next->pre = root;
    // root->next->next = new DLLNode(6);
    // root->next->next->pre = root->next;
    // Dprint(root);
    // Dprint(Dreverse(root));
    return 0;
}