class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* leftpre = dummy;
        for (int i = 0; i < left - 1; i++) {
            leftpre = leftpre->next;
        }

        ListNode* curr = leftpre->next;
        
        ListNode* prev = nullptr;
        for (int i = 0; i <= right - left; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        leftpre->next->next = curr; 
        leftpre->next = prev; 

        return dummy->next;  
    }
};
