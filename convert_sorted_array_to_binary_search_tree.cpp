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
private:
    TreeNode *sorted_array2BST(std::vector<int> &nums, int begin, int end)
    {
        if(begin > end)
        {
            return NULL;
        }
        
        int middle = begin + (end - begin) / 2;
        TreeNode *head = new TreeNode(nums[middle]);
        head->left = sorted_array2BST(nums, begin, middle - 1);
        head->right = sorted_array2BST(nums, middle + 1, end);
        return head;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
        {
            return NULL;
        }
        
        return sorted_array2BST(nums, 0, nums.size() - 1);
    }
};