class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        set<int> s(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        while(curr->next != NULL)
        {
            if(s.find(curr->next->val) != s.end())
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};