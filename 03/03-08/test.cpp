#include "test.h"
using namespace std;
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
    {
        return l2;
    }
    if (!l2)
    {
        return l1;
    }
    ListNode *tmp = new ListNode(0);
    ListNode *ans = tmp;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            ans->next = new ListNode(l1->val);
            ans = ans->next;
            l1 = l1->next;
        }
        else
        {
            ans->next = new ListNode(l2->val);
            ans = ans->next;
            l2 = l2->next;
        }
    }
    if (l1)
    {
        ans->next = l1;
    }
    if (l2)
    {
        ans->next = l2;
    }
    return tmp->next;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *ans = mergeTwoLists(l1, l2);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}