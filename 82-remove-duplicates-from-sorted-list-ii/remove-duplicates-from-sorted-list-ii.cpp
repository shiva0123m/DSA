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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL)
        {
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* curr=head;
        ListNode* temp=dummy;

        while(curr!=NULL)
        {
            if(curr->next!=NULL && curr->next->val==curr->val)
            {
                int value=curr->val;
                while(curr!=NULL && curr->val==value)
                {
                    curr=curr->next;
                }
                temp->next=curr;
            }
            else
            {
                temp=curr;
                curr=curr->next;
            }
        }  
        return dummy->next;                   
    }
};