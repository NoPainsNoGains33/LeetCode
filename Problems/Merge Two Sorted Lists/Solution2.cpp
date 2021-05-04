/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *head = new ListNode ();
        ListNode *prev = head;
        while (1){
            if (!l1){
                prev -> next = l2;
                break;
            }
            if (!l2){
                prev -> next = l1;
                break;
            }
            if (l1 -> val < l2 -> val){
                prev -> next = l1;
                prev = prev -> next;
                l1 = l1 -> next;
            }
            else{
                prev -> next = l2;
                prev = prev -> next;
                l2 = l2 -> next;
            }
        }
        return head -> next;
    }
};
