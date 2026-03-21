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
        if(head==NULL)
        {
            return head;
        }    
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;
        ListNode* ans=dummy;

        while(temp!=NULL && temp->next!=NULL)
        {
            while(temp->next!=NULL && temp->next->val==val) 
            {
                temp=temp->next;
            }
            dummy->next=temp->next;
            dummy=dummy->next;
            temp=temp->next;
        }
        return ans->next;
    }
};