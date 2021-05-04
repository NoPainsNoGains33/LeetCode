class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        vector<int> ans;
        while (true){
            int temp = numbers[left] + numbers[right];
            if (temp == target){
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            }
            else if (temp > target){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};
