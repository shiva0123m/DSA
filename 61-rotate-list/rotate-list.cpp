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
        ListNode* rotateRight(ListNode* head, int k) 
        {
            if(head==NULL || k==0)return head;
            ListNode* dummy=new ListNode(0);

            dummy->next=head;
            ListNode* front=head;
            int listLength=0;   
            while(front!=NULL)
            {
                front=front->next;
                listLength++;
            }
            front=dummy;
            k=k%listLength;
            if (k == 0) return head;
            int kthFromBack=listLength-k;
            while(kthFromBack--)
            {
                front=front->next;
            }
            ListNode* newHead=front->next;
            ListNode* temp=newHead;

            while(temp!=NULL && temp->next!=NULL)
            {
                temp=temp->next;
            }
            ListNode *end=temp;
            end->next=head;
            front->next=NULL;
            return newHead;
        }
};