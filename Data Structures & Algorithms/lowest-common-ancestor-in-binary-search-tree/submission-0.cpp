/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* cur, TreeNode*p, TreeNode*q, TreeNode*root){
        if (cur->val==p->val) return p;
        if (cur->val==q->val) return q;
        if (cur->val > p->val && cur->val > q->val){
            return lca(cur->left,p,q,root);
        }
        else if (cur->val>p->val && cur->val<q->val || cur->val<p->val && cur->val>q->val){
            return cur;
        }
        else if(cur->val < p->val && cur->val < q->val){
            return lca(cur->right, p,q,root);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node=root;
        return lca(node,p,q,root);
    }
};
