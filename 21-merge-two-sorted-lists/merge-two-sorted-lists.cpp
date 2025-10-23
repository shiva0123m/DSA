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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *num1=list1;
        ListNode* num2=list2;
        ListNode* ans=new ListNode();
        ListNode* head=ans;
        while(num1!=NULL && num2!=NULL )
        {
            if(num1->val<num2->val)
            {
                ans->next=new ListNode(num1->val);
                num1=num1->next;
            }
            else
            {
                ans->next=new ListNode(num2->val);
                num2=num2->next;
            }
            ans=ans->next;
        }

        while(num1!=NULL)
        {
            ans->next=new ListNode(num1->val);
            num1=num1->next;
            ans=ans->next;
        }
        while(num2!=NULL)
        {
            ans->next=new ListNode(num2->val);
            num2=num2->next;
            ans=ans->next;
        }  
        return head->next;  
    }
};