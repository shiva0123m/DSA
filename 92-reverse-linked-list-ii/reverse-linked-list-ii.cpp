class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* front = head;
        ListNode* prev = dummy;

        for(int i = 1; i < left; i++)
        {
            front = front->next;
            prev = prev->next;
        }

        ListNode* tail = front;   
        ListNode* next = NULL;

        int duration = right - left + 1;  

        ListNode* revPrev = NULL; 

        while(front != NULL && duration--)
        {
            next = front->next;
            front->next = revPrev;   
            revPrev = front;
            front = next;
        }

        prev->next = revPrev;  
        tail->next = front;     

        return dummy->next;
    }
};