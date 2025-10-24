#include <unordered_set>

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;  

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_set<int> duplicates;
        
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                duplicates.insert(curr->val);
            }
            curr = curr->next;
        }
        
        curr = dummy;
        while (curr && curr->next) {
            if (duplicates.count(curr->next->val)){
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        
        return dummy->next; 
    }
};
