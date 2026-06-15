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
    TreeNode* helper( vector<int>&preorder, vector<int>&inorder, map<int,int>&m, int preStart, int preEnd, int inStart, int inEnd){
        int n = preorder.size();
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        TreeNode*root = new TreeNode(preorder[preStart]);
        
        int idx = m[preorder[preStart]];
        int left_sz = idx - inStart;
        int right_sz = inEnd -idx;
        root->left = helper( preorder, inorder, m, preStart+1, preStart+left_sz, inStart, inStart+left_sz-1);
        root->right = helper(preorder, inorder, m, preStart+1+left_sz, preEnd, idx+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        map<int,int> m;
        for (int i=0; i<n; i++){
            m[inorder[i]]=i;
        }
        return helper(preorder, inorder, m, 0, n-1, 0 ,n-1);
    }
};
