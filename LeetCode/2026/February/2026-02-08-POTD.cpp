class Solution 
{
public:

    int solve(TreeNode *root)
    {
        if(!root) return 0;
        int l = solve(root->left) , r = solve(root->right);
        if(abs(l-r) > 1 || l == -1 || r == -1) return -1;
        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) 
    {
        return solve(root) != -1;
    }
};