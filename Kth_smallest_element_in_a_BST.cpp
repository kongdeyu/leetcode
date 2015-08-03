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
    int kthSmallest(TreeNode* root, int k) {
        assert(root != NULL);
        
        int res = 0;
        kth_smallest(root, k, res);
        return res;
    }
    
private:
    bool kth_smallest(TreeNode *root, int &idx, int &res)
    {
        if(root->left != NULL && kth_smallest(root->left, idx, res))
        {
            return true;
        }
        
        if(--idx == 0)
        {
            res = root->val;
            return true;
        }
        
        if(root->right != NULL && kth_smallest(root->right, idx, res))
        {
            return true;
        }
        return false;
    }
};