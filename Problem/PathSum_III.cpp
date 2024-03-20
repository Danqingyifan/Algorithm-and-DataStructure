// Problem Number: 437
#include <vector>
#include <iostream>
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
    int count = 0;

    void FindPath(TreeNode *root, long targetSum)
    {
        if (!root)
            return;
        if (root->val == targetSum)
        {
            count++;
        }
        FindPath(root->left, targetSum - root->val);
        FindPath(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode *root, long targetSum)
    {
        if (root)
        {
            FindPath(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return count;
    }
};