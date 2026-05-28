/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, unordered_map<Node*,Node*>& seen){
        if (seen.count(node)) return seen[node];
        Node* temp = new Node(node->val);
        seen[node]=temp;
        for (auto u:node->neighbors){
            temp->neighbors.push_back(dfs(u,seen));
        }
        return temp;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*,Node*> seen;
        return dfs(node,seen);
    }
};
