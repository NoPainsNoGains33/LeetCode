class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> hash_map;
        for (int i = 0; i < words.size(); i++)
            hash_map[words[i]].push_back(i);
        int distance = INT_MAX;
        for (auto i:hash_map[word1])
            for (auto j:hash_map[word2])
                distance = abs(i - j) < distance?abs(i - j):distance;
        return distance;
    }
};

// East collection but I made it O(n^2) & O (n), not good
