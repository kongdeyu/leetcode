
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        
        if(p == NULL)
        {
            return q;
        }
        
        if(q == NULL)
        {
            return p;
        }
        
        std::vector<TreeNode *> vec_path2p;
        path2node(root, p, vec_path2p);
        std::vector<TreeNode *> vec_path2q;
        path2node(root, q, vec_path2q);
        TreeNode *res = NULL;
        for(std::vector<TreeNode *>::size_type idx = 0; idx < vec_path2p.size() && idx < vec_path2q.size(); idx++)
        {
            if(vec_path2p[idx] != vec_path2q[idx])
            {
                break;
            }
            
            res = vec_path2p[idx];
        }
        return res;
    }
    
    bool path2node(TreeNode *root, TreeNode *node, std::vector<TreeNode *> &path)
    {
        if(root == NULL)
        {
            return false;
        }
        
        path.push_back(root);
        if(root == node || path2node(root->left, node, path) || path2node(root->right, node, path))
        {
            return true;
        }
        
        path.pop_back();
        return false;
    }
};