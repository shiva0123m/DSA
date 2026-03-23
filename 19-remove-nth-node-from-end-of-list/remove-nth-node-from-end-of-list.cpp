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
class Solution 
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            ListNode* front=head;
            ListNode* back=head;
            if(head==NULL && head->next==NULL)return head;
            int steps=n;
            while(n--)
            {
                front=front->next;
            }
            if(front == NULL)
            {
                return head->next;
            }

            while(front!=NULL && front->next!=NULL)
            {
                front=front->next;
                back=back->next;
            }
            back->next=back->next->next;
            return head;
        }
};