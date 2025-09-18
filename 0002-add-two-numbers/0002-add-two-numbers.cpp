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
       ListNode *p=l1;
       ListNode *q=l2;
       ListNode *dummy=new ListNode(0);
       ListNode *current=dummy;
       int carry=0;

       while(p!=NULL||q!=NULL)
       {
        if(p)
        {
            carry=carry+p->val;
            p=p->next;
           
        }
         if(q)
        {
            carry=carry+q->val;
            q=q->next;
            
            
        }
     
     
    //  current->next=new ListNode(carry%10);
     current->next = new ListNode(carry % 10);
     carry=carry/10;
     current=current->next;
    

       }
        if(carry!=0)
     {
        current->next=new ListNode(carry);
     }
       return dummy->next;

    }
};