/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* list1=headA;
        ListNode* list2=headB;

        int list1Length=0;

        while(list1!=NULL)
        {
            list1=list1->next;
            list1Length++;
        }

        int list2Length=0;

        while(list2!=NULL)
        {
            list2=list2->next;
            list2Length++;
        }

        int distanceToCover=abs(list2Length-list1Length);
        list1=headA;
        list2=headB;
        if(list1Length>list2Length)
        {
            while(distanceToCover-- && list1!=NULL)
            {
                list1=list1->next;
            }
        }
        else
        {
            while(distanceToCover-- && list2!=NULL)
            {
                list2=list2->next;
            }
        }

        while(list1!=NULL)
        {
            if(list1==list2)
            {
                return list1;
            }
            list1=list1->next;
            list2=list2->next;
        }
        return NULL;
    }
};