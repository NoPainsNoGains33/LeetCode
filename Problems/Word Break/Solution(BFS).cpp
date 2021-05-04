class Solution {
    string str;
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> Q;
        int len = s.size();
        vector<bool> visited(len, false);
        Q.push(0);
        while (!Q.empty()){
            int start = Q.front ();
            Q.pop();
            for (int end = start; end < len; end++){
                if (!visited[start])
                    if (find(wordDict.begin(), wordDict.end(), s.substr(start, end - start + 1)) != wordDict.end()){
                        if (end == len-1)
                            return true;
                        else
                            Q.push(end+1);
                    }
            }
            visited[start] = true;
        }
        return false;
    }
};

// With the optimization: visited, or it will time limit exceeded
