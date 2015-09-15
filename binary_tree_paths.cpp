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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> paths;
        if(root == NULL)
        {
            return paths;
        }
        
        binary_tree_paths(root, "", paths);
        return paths;
    }
    
    void binary_tree_paths(TreeNode *root, std::string path, std::vector<std::string> &paths)
    {
        path.append(std::to_string(root->val));
        if(root->left == NULL && root->right == NULL)
        {
            paths.push_back(path);
            return;
        }
        
        path.append("->");
        if(root->left != NULL)
        {
            binary_tree_paths(root->left, path, paths);
        }
        
        if(root->right != NULL)
        {
            binary_tree_paths(root->right, path, paths);
        }
    }
};