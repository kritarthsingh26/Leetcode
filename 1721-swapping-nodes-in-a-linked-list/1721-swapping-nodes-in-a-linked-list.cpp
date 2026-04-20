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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        
         ListNode * p=head;
          ListNode * q=head;
           ListNode * temp=NULL;
           
            for(int i=1;i<k;i++)
            {
             
                p=p->next;
                
            } 
            temp=p;

            while(temp->next!=NULL)
            {
                temp=temp->next;
                q=q->next;
            }

            //q reach to resultant place

            // now r 

            int x=q->val;

            q->val=p->val;
            p->val=x;
            

            return head;

            
    }
};