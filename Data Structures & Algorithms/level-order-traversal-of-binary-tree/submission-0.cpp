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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root==nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int sz=1;
        while (!q.empty()){
            int temp=0;
            vector<int> p;
            for (int i=0; i<sz; i++){
                TreeNode* x = q.front();
                p.push_back(x->val);
                q.pop();
                if (x->left){
                    q.push(x->left);
                    temp++;
                }
                if (x->right){
                    q.push(x->right);
                    temp++;
                }
            }
            sz=temp;
            if (!p.empty())ans.push_back(p);
        }
        return ans;
    }
};
