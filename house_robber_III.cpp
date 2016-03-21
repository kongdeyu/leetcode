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
    int rob(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            return root->val;
        }
        
        if(_map_node2val.find(root) != _map_node2val.end())
        {
            return _map_node2val[root];
        }
        
        int val_with_self = root->val;
        if(root->left != NULL)
        {
            val_with_self += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right != NULL)
        {
            val_with_self += rob(root->right->left) + rob(root->right->right);
        }
        
        int val_without_self = rob(root->left) + rob(root->right);
        
        _map_node2val.insert(std::make_pair(root, std::max(val_with_self, val_without_self)));
        return _map_node2val[root];
    }
    
private:
    std::map<TreeNode *, int> _map_node2val;
};