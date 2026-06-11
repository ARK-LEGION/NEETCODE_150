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
        queue<tuple<TreeNode*,long,long>> q;
        q.push(tuple{root,INT_MIN,INT_MAX});
        while(!q.empty()){
            auto [node, lb,ub] = q.front();
            q.pop();
            if (node->val>lb && node->val<ub){
                if (node->left)q.push(tuple{node->left,lb,node->val});
                if (node->right)q.push(tuple{node->right, node->val,ub});
            }
            else return false;
        }
        return true;
    }
};
