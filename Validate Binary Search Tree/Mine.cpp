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
    int findLargest (TreeNode *root){
        TreeNode *previous = root;
        while (root != NULL){
            previous = root;
            root = root -> right;       
        }
        return previous -> val;
    }
    int findSmallest (TreeNode* root){
        TreeNode *previous = root;
        while (root != NULL){
            previous = root;
            root = root -> left;       
        }
        return previous -> val;
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        if (root -> left == NULL && root -> right == NULL)
            return true;
        if (root -> left == NULL && root -> right != NULL){
            if (isValidBST (root -> right) && root -> val < findSmallest (root -> right))
                return true;
            return false;
        }
        if (root ->left != NULL && root -> right == NULL)
        {
            if (isValidBST (root -> left) && root -> val > findLargest (root -> left))
                return true;
            return false;
        }
        if (isValidBST (root -> left) && isValidBST (root -> right) && root -> val > findLargest (root -> left) && root -> val < findSmallest (root -> right))
            return true;
        return false;
    }
};
