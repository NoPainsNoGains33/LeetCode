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
    int result = 0;
    int sum1;
public:
    void traversal (TreeNode* root, int currentSum, unordered_map <int, int> hash_map){
        currentSum += root->val;
        if (currentSum == sum1)
            result++;
        if (hash_map.find(currentSum - sum1) != hash_map.end())
            result += hash_map[currentSum - sum1];
        hash_map[currentSum]++;
        if (root -> left)
            traversal (root->left, currentSum, hash_map);
        if (root -> right)
            traversal (root->right, currentSum, hash_map);
        
    }
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        sum1 = sum;
        traversal (root, 0, unordered_map<int, int>{});
        return result;
    }
};

//Prefix sum. REALLY useful!
