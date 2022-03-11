#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <queue>
using namespace std;
class LinkedNode
{
public:
    LinkedNode() : val(0), next(nullptr) {}
    LinkedNode(int val, LinkedNode *next = 0) : val(val), next(next) {}
    int val;
    LinkedNode *next;
};

class DLLNode
{
public:
    DLLNode(int val = 0, DLLNode *pre = 0, DLLNode *next = 0) : val(val), pre(pre), next(next){};

    int val;
    DLLNode *pre;
    DLLNode *next;
};

LinkedNode *reverseList(LinkedNode *head)
{
    if (head->next == 0)
        return head;
    LinkedNode *pre = 0;
    LinkedNode *cur = head;
    while (cur)
    {
        LinkedNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void printList(LinkedNode *head)
{
    LinkedNode *p;
    for (p = head; p; p = p->next)
    {
        cout << p->val << ", ";
    }
    cout << endl;
}

class MyQueue
{
    LinkedNode *head;
    LinkedNode *tail;
    int __size;

public:
    MyQueue() : head(0), tail(0), __size(0) {}
    bool isEmpty()
    {
        return __size == 0;
    }
    int size()
    {
        return __size;
    }
    void push(int el)
    {
        LinkedNode *p = new LinkedNode(el);
        if (head == 0)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
        __size++;
    }
    int pop()
    {

        int ans = -1;
        if (head)
        {
            LinkedNode *p = head;
            ans = head->val;
            head = head->next;
            delete p;
            __size--;
        }
        if (head == 0)
        {
            tail = 0;
        }

        return ans;
    }
    int peek()
    {
        int ans = -1;
        if (head)
            ans = head->val;
        return ans;
    }
};

// class MyStack
// {
//     LinkedNode *head;
//     int __size;
// public:
//     MyStack() : head(0), __size(0) {}
//     bool isEmpty()
//     {
//         return __size == 0;
//     }
//     int size()
//     {
//         return __size;
//     }
//     void push(int el)
//     {
//         head = new LinkedNode(el, head);
//         __size++;
//     }
//     void pop()
//     {
//         if (head)
//         {
//             LinkedNode *p = head;
//             head = head->next;
//             __size--;
//             delete p;
//         }
//     }
//     int peek()
//     {
//         return head ? head->val : -1;
//     }
// };

class MyStack
{
    int size;
    LinkedNode *head;

public:
    MyStack()
    {
        size = 0;
        head = new LinkedNode(0);
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(int val)
    {
        LinkedNode *tmp = new LinkedNode(val);
        tmp->next = head->next;
        head->next = tmp;
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            cout << "栈是空的…" << endl;
            return;
        }
        LinkedNode *tmp = head->next;
        head->next = tmp->next;
        delete tmp;
        size--;
    }
    int top()
    {
        if (size == 0)
        {
            cout << "栈中没有元素…… 返回-1" << endl;
            return -1;
        }
        return head->next->val;
    }
};
class MyDeque
{
    int size;
    DLLNode *head;
    DLLNode *tail;

public:
    MyDeque() : size(0), head(0), tail(0) {}
    bool isEmpty()
    {
        return size == 0;
    }
    int length()
    {
        return size;
    }
    void push_front(int val)
    {
        DLLNode *p = new DLLNode(val);
        if (head == 0)
        {
            head = p;
            tail = p;
        }
        else
        {
            p->next = head;
            head->pre = p;
            head = p;
        }
        size++;
    }
    void push_back(int val)
    {
        DLLNode *p = new DLLNode(val);
        if (tail == 0)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            p->pre = tail;
            tail = p;
        }
        size++;
    }
    int pop_front()
    {
        int ans = -1;
        if (head)
        {
            DLLNode *p = head;
            ans = head->val;
            if (head == tail)
            {
                head = tail = 0;
            }
            else
            {
                head = head->next;
                head->pre = 0;
            }
            delete p;
        }
        return ans;
    }
    int pop_back()
    {
        int ans = -1;
        if (tail)
        {
            DLLNode *p = tail;
            ans = tail->val;
            if (head == tail)
            {
                head = tail = 0;
            }
            else
            {
                tail = tail->pre;
                tail->next = 0;
            }
            delete p;
        }
        return ans;
    }
};

class MinStack
{
    stack<int> s;
    stack<int> _min;

public:
    MinStack() {}
    void push(int val)
    {
        if (s.empty())
        {
            _min.push(val);
        }
        s.push(val);
        _min.push(val < _min.top() ? val : _min.top());
    }
    void pop()
    {
        s.pop();
        _min.pop();
    }
    int min()
    {
        return _min.top();
    }
    int size()
    {
        return s.size();
    }
};

class StoQ
{ //原则1pushs到pops一次到完 2popos不空不可到
    stack<int> pushs;
    stack<int> pops;
    // pushs -> pops
    void pushTopop()
    {
        if (pops.empty())
        {
            while (!pushs.empty())
            {
                int tmp = pushs.top();
                pops.push(tmp);
                pushs.pop();
            }
        }
    }

public:
    void push(int val)
    {
        pushs.push(val);
        pushTopop();
    }

    int pop()
    {
        if (pops.empty() && pushs.empty())
        {
            throw "队列是空的...";
        }
        pushTopop();
        int ans = pops.top();
        pops.pop();
        return ans;
    }
};

class QtoS
{
    queue<int> A;
    queue<int> B;

public:
    void push(int val)
    {
        if (A.empty())
        {
            B.push(val);
        }
        else
        {
            A.push(val);
        }
    }

    int pop()
    {
        if (A.empty() && B.empty())
            throw "\n\n栈空了...\n";
        if (A.empty())
        {
            while (1)
            {
                int tmp = B.front();
                B.pop();
                if (B.empty())
                    return tmp;
                A.push(tmp);
            }
        }
        else
        {
            while (1)
            {
                int tmp = A.front();
                A.pop();
                if (A.empty())
                    return tmp;
                B.push(tmp);
            }
        }
    }
};

int main()
{
    srand((unsigned int)time(0));
    QtoS A;
    int n = 9;
    for (int i = 0; i < 9; i++)
    {
        A.push(/*rand() % 13*/ i);
    }
    for (int i = 0; i < 9; i++)
    {
        cout << A.pop() << ", ";
    }
    // A.pop();
    try
    {
        int z = A.pop();
        cout << z << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    // MyDeque A;
    // A.push_back(0);
    // A.push_front(1);
    // A.push_front(2);
    // A.push_back(-1);
    // for (int i = 0; i < 2; i++)
    //     cout << A.pop_back() << ", ";
    // cout << endl;
    // for (int i = 0; i < 2; i++)
    //     cout << A.pop_front() << ", ";
    return 0;
}