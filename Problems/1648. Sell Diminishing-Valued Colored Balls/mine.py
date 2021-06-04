class Solution:
    
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        MODULO = 10 ** 9 + 7
        
        # Build map first
        num_to_cnt_map = {}
        for num in inventory:
            num_to_cnt_map[num] = num_to_cnt_map.get(num, 0) + 1
        num_to_cnt = sorted(num_to_cnt_map.items(), reverse=True)
        
        # Find the smallest num that can't give enough balls for order
        left, right = 0, max(inventory)
        while left <= right:
            middle = (left + right) // 2
            if self.canHaveEnoughBalls(middle, orders, num_to_cnt):
                left = middle + 1
            else:
                right = middle - 1
        
        # Left is the number we need
        profit = 0
        for num, cnt in num_to_cnt:
            if num <= left:
                break
            orders -= (num - left) * cnt
            profit += (num + left + 1) * (num - left) // 2 * cnt
            
        
        profit += left * orders
        
        return profit % MODULO
    
    def canHaveEnoughBalls(self, middle, orders, num_to_cnt):
        for num, cnt in num_to_cnt:
            if num <= middle:
                break
            orders -= (num - middle) * cnt
            if orders <= 0:
                return True
        return orders <= 0
        

    
