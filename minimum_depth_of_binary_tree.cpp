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
    int minDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        
        int left_depth = INT_MAX;
        if(root->left != NULL)
        {
            left_depth = 1 + minDepth(root->left);
        }
        
        int right_depth = INT_MAX;
        if(root->right !=  NULL)
        {
            right_depth = 1 + minDepth(root->right);
        }
        return std::min(left_depth, right_depth);
    }
};