class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> Stack;
        int l = nums.size() - 1, r = 0;
        for (int i = 0; i < nums.size(); i++){
            while (!Stack.empty() && nums[Stack.top()] > nums[i]){
                l = min (l, Stack.top());
                Stack.pop();
            }
            Stack.push(i);
        }
        stack<int> temp;
        Stack.swap(temp);
        for (int j = nums.size() - 1; j >= 0; j--){
            while (!Stack.empty() && nums[Stack.top()] < nums[j]){
                r = max (r, Stack.top());
                Stack.pop();
            }
            Stack.push(j);
        }
        return l < r? r-l+1:0;
    }
};

// Use stack way, find the boundary element
