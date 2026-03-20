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
        ListNode* merge(ListNode* left,ListNode* right)
        {
            ListNode* dummy=new ListNode(0);
            ListNode* ans=dummy;

            while(left!=NULL && right!=NULL)
            {
                if(left->val<right->val)
                {
                    dummy->next=left;
                    left=left->next;
                }
                else
                {
                    dummy->next=right;
                    right=right->next;
                }
                dummy=dummy->next;
            }
            while(left!=NULL)
            {
                dummy->next=left;
                left=left->next;
                dummy=dummy->next;
            }
            while(right!=NULL)
            {
                dummy->next=right;
                right=right->next;
                dummy=dummy->next;
            }
            return ans->next;
        }
        ListNode* findMid(ListNode* head)
        {
            ListNode* slow=head;
            ListNode* fast=head->next;

            while(fast!=NULL && fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }
        ListNode* sortList(ListNode* head) 
        {
            if(head==NULL || head->next==NULL)
            {
                return head;
            }
            ListNode* left=head;

            ListNode* mid=findMid(head);
            ListNode* right= mid->next;
            mid->next=NULL;

            left=sortList(left);
            right=sortList(right);

            return merge(left,right);
        }
};