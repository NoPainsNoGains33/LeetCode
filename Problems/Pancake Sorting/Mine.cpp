class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int len = arr.size();
        vector<int> answer;
        vector<int> result;
        for (int i = 1; i <= len; i++)
            answer.push_back (i);
        int currentNumber = len;
        while (currentNumber != 1){
            if (arr == answer)
                break;
            int i = 0;
            while (arr[i++] != currentNumber);
            if (i != currentNumber){
                result.push_back(i);
                reverse(arr.begin(), arr.begin()+i);
                result.push_back(currentNumber);
                reverse(arr.begin(), arr.begin()+currentNumber);
            }
            currentNumber--;
        }
        return result;
    }
};

