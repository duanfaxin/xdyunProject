#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *dfs(TreeNode *cloned, TreeNode *target)
    {
        if (!cloned)
            return NULL;
        if (cloned->val == target->val)
            return cloned;

        TreeNode *res = dfs(cloned->left, target);
        if (res)
        {
            return res;
        }
        res = dfs(cloned->right, target);
        if (res)
        {
            return res;
        }

        return NULL;
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                            TreeNode *target)
    {
        return dfs(cloned, target);
    }
};