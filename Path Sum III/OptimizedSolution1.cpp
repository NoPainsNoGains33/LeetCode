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
    unordered_map <int, int> hash_map;
public:
    void traversal (TreeNode* root, int currentSum){
        currentSum += root->val;
        if (currentSum == sum1)
            result++;
        // if (hash_map.find(currentSum - sum1) != hash_map.end())
        result += hash_map[currentSum - sum1];
        hash_map[currentSum]++;
        if (root -> left)
            traversal (root->left, currentSum);
        if (root -> right)
            traversal (root->right, currentSum);
        hash_map[currentSum]--;
        
    }
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        sum1 = sum;
        traversal (root, 0);
        return result;
    }
};

// Pass an unorderd_map is really slow. Understand more about traceback!
// I could use the same hash map, whenever I finished my program, eliminate my effect!
