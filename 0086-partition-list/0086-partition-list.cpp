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
    ListNode* partition(ListNode* head, int x) 
    {
        //us list me ye sb chhez kaena is not possible that why 2 lists

        ListNode * small=new ListNode(0);
        ListNode * large=new ListNode(0);

        ListNode * chota=small;
        ListNode * bada=large;

        while(head!=NULL)
        {
            if(head->val<x)
            {
                chota->next=head;
                chota=chota->next;

            }
            else
            {
                bada->next=head;
                bada=bada->next;
            }
            head=head->next;
        }
        chota->next=large->next;

        bada->next=NULL;
        

        return small->next;
    }
};