class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {

        if(head==NULL)return head;
        
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;

        // move first to kth node
        for(int i = 1; i < k; i++)
            first = first->next;

        ListNode* kthFromStart = first;

        // move temp to end while moving second
        while(first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }

        ListNode* kthFromEnd = second;

        // swap values
        int val = kthFromStart->val;
        kthFromStart->val = kthFromEnd->val;
        kthFromEnd->val = val;

        return head;
    }
};