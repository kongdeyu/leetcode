/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *p, TreeNode *q)
    {
        if(p == NULL && q == NULL)
        {
            return true;
        }
        
        if(p == NULL || q == NULL || p->val != q->val)
        {
            return false;
        }
        
        return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};