/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    class node
    {
    public:
        int max_;
        int min_;
        bool isBST;
        int val;
        node(int max_, int min_, bool isBST, int val)
        {
            this->max_ = max_;
            this->min_ = min_;
            this->isBST = isBST;
            this->val = val;
        }
    };
    node sol(TreeNode *root, int &sum)
    {
        if (!root)
        {
            node base(INT_MIN, INT_MAX, true, 0);
            return base;
        }
        node left = sol(root->left, sum);
        node right = sol(root->right, sum);
        if (left.isBST && right.isBST && root->val > left.max_ && root->val < right.min_)
        {
            int local_max = max(root->val, right.max_);
            int local_min = min(root->val, left.min_);
            int val = root->val + left.val + right.val;
            sum = max(sum, val);
            node temp(local_max, local_min, true, val);
            return temp;
        }
        else
        {
            int local_max = INT_MAX;
            int local_min = INT_MIN;
            int val = 0;
            node false_temp(local_max, local_min, false, val);
            return false_temp;
        }
    }
    int maxSumBST(TreeNode *root)
    {
        int sum = 0;
        node ans = sol(root, sum);
        return sum;
    }
};