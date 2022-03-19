#ifndef _EDGE_H_
#define _EDGE_H_
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include "Node.h"
using namespace std;
class Node;
class Edge
{
public:
    int weight;
    Node *from;
    Node *to;
    Edge(int w, Node *f, Node *t) : weight(w), from(f), to(t) {}
};
#endif