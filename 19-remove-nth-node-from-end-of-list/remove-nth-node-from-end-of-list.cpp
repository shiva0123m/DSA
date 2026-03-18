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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* back=dummy;
        ListNode* front=dummy;
        int k=n;
        while(k--)
        {
            front=front->next;
        }
        while(front!=NULL&& front->next!=NULL)
        {
            front=front->next;
            back=back->next;
        }
        if(back->next!=NULL)back->next=back->next->next;
        return dummy->next;
    }
};