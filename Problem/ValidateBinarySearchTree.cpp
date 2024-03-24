// Problem Number: 98
#include <iostream>
#include <string>
#include <stack>
#include <vector>
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
    bool isInPlace(TreeNode *root, long long min, long long max)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val > min && root->val < max)
        {
            return isInPlace(root->left, min, root->val) && isInPlace(root->right, root->val, max);
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        return isInPlace(root, LONG_MIN, LONG_MAX);
    }
};