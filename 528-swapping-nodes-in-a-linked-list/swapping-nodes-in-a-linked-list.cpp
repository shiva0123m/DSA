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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* front=head;
        ListNode* back=head;

        for(int i=1;i<k;i++)
        {
            front=front->next;
        }
        ListNode* kthFromBegin=front;
        ListNode* temp=dummy;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        int fromLast=count-k;
        temp=dummy;
        for(int i=0;i<fromLast;i++)
        {
            temp=temp->next;
        }
        ListNode* kthFromLast=temp;

        int value=kthFromBegin->val;
        kthFromBegin->val=kthFromLast->val;
        kthFromLast->val=value;

        return dummy->next;
    }
};