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
struct pair_hash
{
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2> &pair) const
    {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};
class Solution {
private:
    int result = 0;
    int sum1;
public:
    void calculate_sum (TreeNode* root, int current_sum){
        current_sum = current_sum + root -> val;
        if (current_sum == sum1)
            result++;
        if (root->left)
            calculate_sum (root->left, current_sum);
        if (root->right)
            calculate_sum (root->right, current_sum);
    }
    void traversal (TreeNode* root){
        if (root)
            calculate_sum (root, 0);
        if (root->left)
            traversal(root->left);
        if (root->right)
            traversal(root->right);
            
    }
    int pathSum(TreeNode* root, int sum) {
        sum1 = sum;
        if (!root)
            return 0;
        traversal (root);
        return result;
    }
};
// Pure dfs, find all situations without optimization. AC
