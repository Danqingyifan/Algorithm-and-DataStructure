// Problem Number: 101
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
    bool Compare(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (leftNode && rightNode)
        {
            if (leftNode->val == rightNode->val)
            {
                return Compare(rightNode->right, leftNode->left) && Compare(leftNode->right, rightNode->left);
            }
            else{
                return false;
            }
        }
        else if (!leftNode && !rightNode)
        {
            return true;
        }
        else{
            return false;
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        return Compare(root->left, root->right);
    }
};