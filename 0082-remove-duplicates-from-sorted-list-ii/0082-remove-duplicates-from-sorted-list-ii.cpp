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
   ListNode* deleteDuplicates(ListNode* head) 
{
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr)
    {
        bool duplicate = false;

        // skip all nodes with same value
        while (curr->next && curr->val == curr->next->val)
        {
            duplicate = true;
            curr = curr->next;
        }

        if (duplicate)
        {
            // skip entire duplicate block
            prev->next = curr->next;
        }
        else
        {
            // move prev only when no duplicates
            prev = prev->next;
        }

        curr = curr->next;
    }

    return dummy->next;
}
};