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
    void inorder(TreeNode* root,int& c, int k ,int& res){
        if (root==nullptr || c>=k) return ;
        inorder(root->left,c,k,res);
        c++;
        if (c==k){
            res = root->val;
            return;
        }
        inorder(root->right,c,k,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> inot;
        int c=0;
        int res=0;
        inorder(root,c,k,res);
        return res;
    }
};
