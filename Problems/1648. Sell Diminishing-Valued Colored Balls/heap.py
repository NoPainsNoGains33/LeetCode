class Solution:
    
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        MODULO = 10 ** 9 + 7
        
        res = math.log10(MODULO)
        print(res)
        
        max_heap = [-item for item in inventory]
        # for item in inventory:
        #     heapq.heappush(max_heap, -item)
        heapq.heapify(max_heap)
        res = 0
        while orders:
            max_element = heapq.heappop(max_heap)
            res += -max_element
            heappush(max_heap, max_element + 1)
            orders -= 1
        
        return res % MODULO
            

    
