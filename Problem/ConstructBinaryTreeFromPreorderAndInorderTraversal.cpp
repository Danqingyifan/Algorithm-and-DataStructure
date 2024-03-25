// Problem Number: 104
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        int index = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == preorder[0])
            {
                index = i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};