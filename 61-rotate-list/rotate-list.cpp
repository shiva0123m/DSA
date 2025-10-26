class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        ListNode* current = head;
        int length = 1; 
        while (current->next) {
            current = current->next;
            length++;
        }

        k = k % length;
        if (k == 0) return head;
        // head=[1,2,3,4,5]
        // here 5 ->1 
        current->next = head;
        
        ListNode* newTail = head;
        // here 4->5->1->2->3
        for (int i = 1; i < length - k; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
