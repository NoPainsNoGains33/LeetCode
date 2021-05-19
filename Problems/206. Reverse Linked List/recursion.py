# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        return self.reverseHelper(head)
    
    def reverseHelper(self, head):
        if head is None or head.next is None:
            return head
        
        new_head = self.reverseHelper(head.next)
        head.next.next = head
        head.next = None
            
        return new_head
