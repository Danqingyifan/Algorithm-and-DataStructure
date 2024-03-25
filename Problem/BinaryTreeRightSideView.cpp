// Problem Number: 199
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
    void helper(TreeNode *root, int level, vector<int> &result)
    {
        if (root == nullptr)
        {
            return;
        }
        if (result.size() == level)
        {
            result.push_back(root->val);
        }
        helper(root->right, level + 1, result);
        helper(root->left, level + 1, result);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        helper(root, 0, result);
        return result;
    }
};