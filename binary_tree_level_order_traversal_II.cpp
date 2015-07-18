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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int> > res;
        if(root == NULL)
        {
            return res;
        }
        
        levelOrderBottom(root, 1, res);
        std::reverse(res.begin(), res.end());
        return res;
    }
    
    void levelOrderBottom(TreeNode *root, int depth, std::vector<std::vector<int> > &out)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(out.size() < depth)
        {
            out.push_back(std::vector<int>());
        }
        
        out[depth - 1].push_back(root->val);
        if(root->left !=  NULL)
        {
            levelOrderBottom(root->left, depth + 1, out);
        }
        
        if(root->right != NULL)
        {
            levelOrderBottom(root->right, depth + 1, out);
        }
    }
};