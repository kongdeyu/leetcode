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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > res;
        if(root == NULL)
        {
            return res;
        }
        
        std::queue<TreeNode *> queue_nodes;
        queue_nodes.push(root);
        while(queue_nodes.size())
        {
            std::queue<TreeNode *> temp;
            std::vector<int> row;
            while(queue_nodes.size())
            {
                TreeNode *node = queue_nodes.front();
                queue_nodes.pop();
                row.push_back(node->val);
                if(node->left != NULL)
                {
                    temp.push(node->left);
                }
                if(node->right != NULL)
                {
                    temp.push(node->right);
                }
            }
            res.push_back(row);
            queue_nodes.swap(temp);
        }
        return res;
    }
};