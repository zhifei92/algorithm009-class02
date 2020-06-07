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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* helper(vector<int>& preorder, int i, int j, vector<int>& inorder, int ii, int jj) {
        if (i >= j) return nullptr;
        int rootVal = preorder[i];
        int leftNum = find(inorder.begin() + ii, inorder.end() + jj, rootVal) - inorder.begin() - ii;
        TreeNode* root = new TreeNode(rootVal);
        root->left = helper(preorder, i + 1, i + 1 + leftNum, inorder, ii, ii + leftNum + 1);
        root->right = helper(preorder, i + 1 + leftNum, j, inorder, ii + leftNum + 1, jj);
        return root;
    }
};