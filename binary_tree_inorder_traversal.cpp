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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode *> stack_nodes;
        TreeNode *cur_node = root;
        while(cur_node != NULL || stack_nodes.size())
        {
            if(cur_node != NULL)
            {
                stack_nodes.push(cur_node);
                cur_node = cur_node->left;
            }
            else
            {
                cur_node = stack_nodes.top();
                stack_nodes.pop();
                res.push_back(cur_node->val);
                cur_node = cur_node->right;
            }
        }
        return res;
    }
};