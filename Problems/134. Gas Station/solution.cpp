class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // If sumCost > sumGas, return -1
        int sum = 0, n = gas.size();
        for (int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
        }
        if (sum < 0)
            return -1;
        
        // Iterate over all gas station
        int currTank = 0, startIndex = 0;
        for (int start = 0; start < n; start++){
            currTank += gas[start] - cost[start];
            if (currTank < 0){
                currTank = 0;
                startIndex = start + 1;
            }
        }
        
        return startIndex;
    }
};
