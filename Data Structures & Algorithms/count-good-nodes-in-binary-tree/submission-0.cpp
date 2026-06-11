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
    int helper(TreeNode* cur, int largest){
        if (cur==nullptr) return 0;
        if (largest<=cur->val){
            return 1 + helper(cur->left,cur->val) +helper(cur->right,cur->val);
        }
        return helper(cur->left,largest) + helper(cur->right,largest);
    }
    int goodNodes(TreeNode* root) {
        int largest =root->val;
        return helper(root, largest);
    }
};
