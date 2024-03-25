// Problem Number: 543
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
    int depth(TreeNode *root, int &diameter)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = depth(root->left, diameter);
        int right = depth(root->right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
};