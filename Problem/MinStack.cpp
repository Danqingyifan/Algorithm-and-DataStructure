// Problem Number: 155
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

class MinStack
{
public:
    class Node
    {
    public:
        int val;
        int minTilNow;
        Node *next;
        Node(int val, int minTilNow, Node *next) : val(val), minTilNow(minTilNow), next(next) {}
    };

    MinStack() : topNode(nullptr) {}

    void push(int val)
    {
        Node *node = new Node(val, topNode ? std::min(val, topNode->minTilNow) : val, nullptr);
        if (topNode == nullptr)
        {
            topNode = node;
        }
        else
        {
            node->next = topNode;
            topNode = node;
        }
    }

    void pop()
    {
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top()
    {
        return topNode->val;
    }

    int getMin()
    {
        return topNode->minTilNow;
    }

private:
    Node *topNode;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->topNode();
 * int param_4 = obj->getMin();
 */