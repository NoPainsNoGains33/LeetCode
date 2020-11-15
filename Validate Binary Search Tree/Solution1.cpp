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
    bool isValidBST(TreeNode* root) {
        return helper (root, LONG_MIN, LONG_MAX);
    }
    bool helper (TreeNode* root, long minimum, long maximum){
        if (!root)
            return true;
        if (root -> val >= maximum || root -> val <= minimum)
            return false;
        return helper (root->left, minimum, root->val) && helper (root->right, root->val, maximum);
    }
};
