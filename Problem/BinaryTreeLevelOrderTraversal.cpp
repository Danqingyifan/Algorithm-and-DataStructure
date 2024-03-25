// Problem Number: 102
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
    void separateLevel(TreeNode *root, vector<vector<int>> &result, int level)
    {
        if (root == nullptr)
        {
            return;
        }
        if (result.size() == level)
        {
            result.push_back({});
        }
        result[level].push_back(root->val);
        separateLevel(root->left, result, level + 1);
        separateLevel(root->right, result, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        separateLevel(root, result, 0);
        return result;
    }
};

class SecondSolution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> v;
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};