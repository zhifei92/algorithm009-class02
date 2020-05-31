/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (nullptr == root)
            return {};
        vector<vector<int>> ans;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> curLevel;
            int curSize = que.size();
            for (int i = 0; i < curSize; i++) {
                Node *n = que.front();
                que.pop();
                curLevel.push_back(n->val);
                for (auto cld : n->children) {
                    que.push(cld);
                }
            }
            ans.push_back(curLevel);
        }
        return ans;
    }
};