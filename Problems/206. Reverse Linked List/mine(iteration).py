# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        prev_node = None
        next_node = head.next
        while next_node:
            head.next = prev_node
            prev_node = head
            head = next_node
            next_node = next_node.next
        
        head.next = prev_node
        return head
