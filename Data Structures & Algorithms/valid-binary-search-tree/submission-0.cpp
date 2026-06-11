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
    bool isValidBST(TreeNode* root) {
        int x = -1001;
        int y=1001;
        if (root==nullptr) return true;
        TreeNode* cur = root;
        if (root->left!=nullptr){
            cur = root->left;
            while(cur->right!=nullptr) {
                cur = cur->right;
            }
            x = cur->val;
        }
        if (root->right!=nullptr){
            cur = root->right;
            while (cur->left!=nullptr){
                cur = cur->left;
            }
            y= cur->val;
        }
        return (root->val>x && root->val<y && isValidBST(root->left) && isValidBST(root->right));
    }
};
