#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include "Edge.h"
using namespace std;
class Edge;
class Node
{
public:
    int val;
    int in;
    int out;
    vector<Node *> next;
    vector<Edge *> edges;

public:
    Node(int val) : val(val), in(0), out(0)
    {
    }
};
#endif