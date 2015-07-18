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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        
        int depth_left = INT_MIN;
        if(root->left != NULL)
        {
            depth_left = maxDepth(root->left);
        }
        
        int depth_right = INT_MIN;
        if(root->right != NULL)
        {
            depth_right = maxDepth(root->right);
        }
        
        return std::max(depth_left, depth_right) + 1;
    }
};