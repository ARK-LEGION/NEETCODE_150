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
    void inorder(TreeNode* root,vector<int>&inot ){
        if (root==nullptr) return ;
        inorder(root->left,inot);
        inot.push_back(root->val);
        inorder(root->right, inot);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inot;
        inorder(root, inot);
        return inot[k-1];
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     TreeNode* cur = st.top();
        //     // st.pop();
        //     while (cur->left!=nullptr)st.push(cur),cur = cur->left;
        //     st.push(cur);

        // }
    }
};
