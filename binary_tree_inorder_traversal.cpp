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
        
        TreeNode *cur_node = root;
        while(cur_node != NULL)
        {
            if(cur_node->left == NULL)
            {
                res.push_back(cur_node->val);
                cur_node = cur_node->right;
                continue;
            }
            
            TreeNode *predecessor = cur_node->left;
            while(predecessor->right != NULL && predecessor->right != cur_node)
            {
                predecessor = predecessor->right;
            }
            if(predecessor->right != NULL)
            {
                res.push_back(cur_node->val);
                predecessor->right = NULL;
                cur_node = cur_node->right;
            }
            else
            {
                predecessor->right = cur_node;
                cur_node = cur_node->left;
            }
        }
        return res;
    }
};