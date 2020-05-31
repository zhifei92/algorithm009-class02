/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (nullptr == root)
            return {};
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

    void preorder(TreeNode *root, vector<int> &nodes) {
        if (nullptr == root)
            return;
        nodes.push_back(root->val);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
        return;
    }
};