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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        set<int>st;
        st.insert(nums.begin(),nums.end());
        ListNode* dummy=new ListNode(0);
        ListNode*ans=dummy;
        ListNode* temp=head;
        if(head==NULL)
        {
            return head;
        }
        while(temp!=NULL)
        {
            if(st.find(temp->val)==st.end())
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