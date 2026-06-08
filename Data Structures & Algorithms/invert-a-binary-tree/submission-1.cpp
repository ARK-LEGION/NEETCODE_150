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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        if (root->left ==nullptr && root->right==nullptr) return root;
        // if (root->left==nullptr) {
        //     root->right = root->left;
        //     root->left = nullptr;
        //     return root;
        // }
        // if (root->right==nullptr) {
        //     root->left = root->right;
        //     root->right = nullptr;
        //     return root;
        // }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;

    }   
};
