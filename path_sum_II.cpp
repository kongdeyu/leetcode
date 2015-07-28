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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int> > paths;
        if(root == NULL)
        {
            return paths;
        }
        
        std::vector<int> path;
        path_sum(root, sum, path, paths);
        return paths;
    }
    
private:
    void path_sum(TreeNode *root, int sum, std::vector<int> &path, std::vector<std::vector<int> > &paths)
    {
        path.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL && sum == root->val)
        {
            paths.push_back(path);
        }
        
        if(root->left != NULL)
        {
            path_sum(root->left, sum - root->val, path, paths);
        }
        
        if(root->right != NULL)
        {
            path_sum(root->right, sum - root->val, path, paths);
        }
        
        path.pop_back();
    }
};