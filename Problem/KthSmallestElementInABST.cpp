// Problem Number: 230
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> s;
        TreeNode *current = root;
        while (current != nullptr || !s.empty())
        {
            while (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            k--;
            if (k == 0)
            {
                return current->val;
            }
            current = current->right;
        }
        return -1;
    }
};