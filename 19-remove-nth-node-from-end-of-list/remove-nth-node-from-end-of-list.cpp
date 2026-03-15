class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* front = head;
        ListNode* back = head;

        while(n--)
        {
            front = front->next;
        }

        if(front == NULL)
        {
            return head->next;
        }

        while(front->next != NULL)
        {
            front = front->next;
            back = back->next;
        }

        back->next = back->next->next;

        return head;
    }
};