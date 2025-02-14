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

ListNode* reverse(ListNode*& head){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr!= NULL){
        ListNode* nextnode=curr->next;
        curr->next= prev;
         prev= curr;
         curr= nextnode;
    }

    return prev;
}
    ListNode* doubleIt(ListNode* head) {
       head=reverse(head);
       ListNode* temp= head;
       ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int carry=0;
       while( temp!= NULL){
        int num= temp->val*2 + carry;
            // while(num!=0){
                int digit= num%10;
                curr->next=new ListNode(digit);
                curr= curr->next;
                carry=num/10;
            //     num=num/10;

            // }
        temp= temp->next;

       }

       if( carry !=0){
         curr->next=new ListNode(carry);
            curr= curr->next;

       }
       return reverse( dummy->next);
        
    }
};