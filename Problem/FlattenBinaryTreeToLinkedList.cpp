// Problem Number: 114
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
    void preorderTraversal(TreeNode *root, std::vector<TreeNode *> &res)
    {
        if (root == nullptr)
            return;
        res.push_back(root);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }
    void flatten(TreeNode *root)
    {
        std::vector<TreeNode *> res;
        preorderTraversal(root, res);
        for (int i = 0; i < res.size(); i++)
        {
            res[i]->left = nullptr;
            if (i != res.size() - 1)
                res[i]->right = res[i + 1];
        }
    }
};