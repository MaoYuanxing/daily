
#include "Edge.h"
#include "Node.h"

using namespace std;

class graph
{
public:
    unordered_map<int, Node *> NodeSet;
    unordered_set<Edge *> EdgeSet;
    graph(){};
};

void bfs(Node *node)
{
    if (node == nullptr)
        return;
    queue<Node *> q;
    unordered_set<Node *> set;
    q.push(node);
    set.insert(node);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        cout << cur->val << ", ";
        for (auto i : cur->next)
        {
            if (set.find(i) != set.end())
            {
                set.insert(i);
                q.push(i);
            }
        }
    }
}

void dfs(Node *node)
{
    if (node == nullptr)
        return;
    stack<Node *> s;
    unordered_set<Node *> set;
    s.push(node);
    set.insert(node);
    cout << node->val << ", ";
    while (!s.empty())
    {
        Node *cur = s.top();
        s.pop();
        for (auto i : cur->next)
        {
            if (set.find(i) != set.end())
            {
                set.insert(i);
                s.push(cur);
                s.push(i);
                cout << i->val << ", ";
                break;
            }
        }
    }
}

class test
{
public:
    vector<int> arr;

public:
    void print()
    {
        cout << endl;
        cout << endl;
        for (int i : arr)
            cout << i << ", ";
        cout << endl;
    }
};
vector<Node *> sortedTopology(graph *graph)
{
    vector<Node *> res;
    // key: a node
    // value: in degree
    unordered_map<Node *, int> inMap;
    queue<Node *> zeroInQueue;
    for (auto node = graph->NodeSet.begin();
         node != graph->NodeSet.end(); ++node)
    {
        inMap[node->second] = node->second->in;
        if (node->second->in == 0)
        {
            zeroInQueue.push(node->second);
        }
    }
    while (!zeroInQueue.empty())
    {
        Node *cur = zeroInQueue.front();
        zeroInQueue.pop();
        res.push_back(cur);
        for (auto i : cur->next)
        {
            inMap[i]--;
            if (inMap[i] == 0)
            {
                zeroInQueue.push(i);
            }
        }
    }
    return res;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    test arr;
    arr.arr = a;
    arr.print();
    return 0;
}