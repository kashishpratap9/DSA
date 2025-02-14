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

ListNode* getMiddle(ListNode*&head){
    ListNode* fast=head;
    ListNode*slow=head;
    while( fast!= NULL){
         fast= fast->next;
         if (fast != NULL){
            fast= fast->next;
            slow= slow->next;
         }
    }
    // cout<<slow->val;

    ListNode* slow_head=slow->next;
    slow->next=NULL;
    return slow_head;
}
    void reorderList(ListNode* head) {

        ListNode* temp= head;
       ListNode* slowhead=getMiddle(head);
       ListNode* temp1= reverse(slowhead);

       while(temp!= NULL &&  temp1 != NULL){

        ListNode* newnode=new ListNode(temp1->val);
        newnode->next=temp->next;
        temp->next=newnode;
        
        temp=temp->next->next;
        temp1= temp1->next;
       }

  

 temp= head;
       while( temp!= NULL){
        cout<<temp->val<<" ";
        temp= temp->next;
       }

   

        
    }
};