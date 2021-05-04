class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        index = 0
        sum_gas_remaining = 0
        min_gas_remaining = sys.maxsize
        for i in range(len(gas)):
            sum_gas_remaining += gas[i] - cost[i]
            if sum_gas_remaining < min_gas_remaining:
                min_gas_remaining = sum_gas_remaining
                index = i
        
        if sum_gas_remaining < 0:
            return -1
        return (index + 1) % len(gas)
