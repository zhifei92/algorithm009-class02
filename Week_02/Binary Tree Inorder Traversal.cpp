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
    vector<int> inorderTraversal(TreeNode* root) {
        if (nullptr == root)
            return {};
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

    void inorder(TreeNode *root, vector<int> &nodes) {
        if (nullptr == root)
            return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
        return;
    }
};