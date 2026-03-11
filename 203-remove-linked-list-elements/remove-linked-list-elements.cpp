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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* dummy=new ListNode(0);
        ListNode* ans=dummy;
        ListNode* temp=head;
        if(head==NULL)
        {
            return head;
        }
        while(temp!=NULL)
        {
            if(temp->val!=val)
            {
                dummy->next=temp;
                dummy=dummy->next;
            }
            temp=temp->next;
        }  
        dummy->next=NULL;
        return ans->next;  
    }
};