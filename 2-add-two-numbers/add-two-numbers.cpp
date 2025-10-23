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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *num1=l1;
        ListNode *num2=l2;
        int carry=0;
        ListNode *ans=new ListNode();
        ListNode* head=ans;
        while(num1!=NULL || num2!=NULL || carry!=0)
        {
            int sum=carry;
            if(num1!=NULL)
            {
                sum+=num1->val;
                num1=num1->next;
            }
            if(num2!=NULL)
            {
               sum+=num2->val;
               num2=num2->next;
            }
            ans->next=new ListNode(sum%10);
            ans=ans->next;
            carry=sum/10;    
        }

        return head->next; 
    }
};