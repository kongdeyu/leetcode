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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if(root == NULL)
        {
            return res;
        }
        
        std::stack<TreeNode *> _stack_nodes;
        _stack_nodes.push(root);
        while(_stack_nodes.size())
        {
            TreeNode *cur_node = _stack_nodes.top();
            _stack_nodes.pop();
            if(cur_node->right != NULL)
            {
                _stack_nodes.push(cur_node->right);
            }
            if(cur_node->left != NULL)
            {
                _stack_nodes.push(cur_node->left);
            }
            
            res.push_back(cur_node->val);
        }
        return res;
    }
};