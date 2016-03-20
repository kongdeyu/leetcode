/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
        {
            return;
        }
        
        std::queue<TreeLinkNode *> q_cur;
        std::queue<TreeLinkNode *> q_next;
        q_cur.push(root);
        while(q_cur.size())
        {
            TreeLinkNode *pre = NULL;
            while(q_cur.size())
            {
                TreeLinkNode *cur = q_cur.front();
                q_cur.pop();
                
                if(pre != NULL)
                {
                    pre->next = cur;
                }
                pre = cur;
                
                if(cur->left != NULL)
                {
                    q_next.push(cur->left);
                }
                
                if(cur->right != NULL)
                {
                    q_next.push(cur->right);
                }
            }
            q_cur.swap(q_next);
        }
    }
};