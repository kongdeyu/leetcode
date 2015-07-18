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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
    
    bool isBalanced(TreeNode *root, int &depth)
    {
        if(root ==  NULL)
        {
            return true;
        }
        
        int left_depth = 0;
        int right_depth = 0;
        if(isBalanced(root->left, left_depth) && isBalanced(root->right, right_depth))
        {
            depth = std::max(left_depth, right_depth) + 1;
            return abs(left_depth - right_depth) <= 1;
        }
        
        return false;
    }
};