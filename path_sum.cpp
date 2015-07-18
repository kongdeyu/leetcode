/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root == NULL)
    {
        return false;
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        if(sum == root->val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    if(root->left != NULL && hasPathSum(root->left, sum - root->val))
    {
        return true;
    }
    
    if(root->right != NULL && hasPathSum(root->right, sum - root->val))
    {
        return true;
    }
    return false;
}