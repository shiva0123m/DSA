class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* beforeDummy = new ListNode(0);
        ListNode* afterDummy = new ListNode(0);

        ListNode* before = beforeDummy;
        ListNode* after = afterDummy;

        ListNode* curr = head;

        while(curr != NULL)
        {
            if(curr->val < x)
            {
                before->next = curr;
                before = before->next;
            }
            else
            {
                after->next = curr;
                after = after->next;
            }
            curr = curr->next;
        }

        after->next = NULL;

        before->next = afterDummy->next;

        return beforeDummy->next;
    }
};