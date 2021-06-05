# 123
class Solution:
    
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        MODULO = 10 ** 9 + 7
        
        inventory = sorted(inventory, reverse=True)
        res, next_index = 0, 0
        length = len(inventory)
        curr_num = inventory[0]
        while orders:
            while next_index < length and inventory[next_index] == curr_num:
                next_index += 1
            next_num = 0 if next_index == length else inventory[next_index]
            total_num = next_index
            if orders < total_num * (curr_num - next_num):
                new_count = orders // total_num
                remainder = orders % total_num
                next_num = curr_num - new_count
                res += (curr_num + next_num + 1) * new_count * total_num // 2 + remainder * next_num
                break
            res += ((curr_num + next_num + 1) * (curr_num - next_num) * total_num // 2) % MODULO
            orders -= (curr_num - next_num) * total_num
            curr_num = next_num
        
        return res % MODULO
            

    
