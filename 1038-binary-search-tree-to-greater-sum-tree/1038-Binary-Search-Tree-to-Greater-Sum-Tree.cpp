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
private:
    int accumulatedSum = 0;
    
    void reverseInOrder(TreeNode* root) {
        if (!root) return;

        reverseInOrder(root->right);

        accumulatedSum += root->val;
        root->val = accumulatedSum;

        reverseInOrder(root->left);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        accumulatedSum = 0;
        reverseInOrder(root);
        return root;
    }
};