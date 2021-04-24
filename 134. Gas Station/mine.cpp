class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // If sumCost > sumGas, return -1
        int sum = 0, n = gas.size();
        vector<int> gasRemain(n);
        for (int i = 0; i < gas.size(); i++){
            gasRemain[i] = gas[i] - cost[i];
            sum += gasRemain[i];
        }
        if (sum < 0)
            return -1;
        
        // Iterate over all gas station
        for (int start = 0; start < n; start++){
            // Only start from gasRemain >= 0 
            if (gasRemain[start] < 0)
                continue;
            int currTank = 0, visited = 0;
            while (visited < n){
                int currStation = (start + visited) % n;
                currTank += gasRemain[currStation];
                if (currTank < 0)
                    break;
                visited++;
            }
            if (visited == n)
                return start;
        }
        
        return -1;
    }
};
