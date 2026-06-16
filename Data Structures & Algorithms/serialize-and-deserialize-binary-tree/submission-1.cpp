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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while (!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if (!cur) {
                s+="N,";
            }
            else {s+= to_string(cur->val) + ",";
            q.push(cur->left);
            q.push(cur->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        queue<TreeNode*> q;
        string val;
        getline(ss,val,',');
        if (val=="N") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);
        while (getline(ss, val, ',')){
            TreeNode* node = q.front();
            q.pop();
            if (val!="N") node->left = new TreeNode(stoi(val)), q.push(node->left);
            getline(ss,val,',');
            if (val!="N") node->right = new TreeNode(stoi(val)), q.push(node->right);
        }
        return root;

    }
};
