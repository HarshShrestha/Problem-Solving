# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        curr = head
        front = curr.next
        while(front):
            while(front and front.val == curr.val):
                front = front.next
            curr.next = front
            curr = curr.next

        return head