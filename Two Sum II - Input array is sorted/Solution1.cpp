class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        while (true){
            int temp = numbers[left] + numbers[right];
            if (temp == target)
                return {left + 1, right + 1};
            else if (temp > target)
                right--;      
            else
                left++; 
        }
        return {-1, -1};
    }
};
