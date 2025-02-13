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
int findVal(ListNode* list1, int index){
    int i=0;
    ListNode* temp=list1;
    int val=0;
    while(temp!= NULL){
        if( i==index){
             val = temp->val;
             break;
        }
        temp= temp->next;
        i++;
    }

    return val;
    

}
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // int value1= findVal(list1, a);
        // int value2=findVal(list1, b);

         ListNode* temp=list1;
         ListNode* temp1=list2;
         ListNode* prev= NULL;
         ListNode* dummy= new ListNode(-1);
         ListNode* curr= dummy;
         int i=0;

         while( temp!= NULL){
            if(i==a){
                break;
            }
            ListNode* newnode=new ListNode(temp->val);
            curr->next=newnode;
            curr= curr->next;
            temp= temp->next;
            i++;

         }
         curr->next=list2;
         while( curr->next!= NULL){
            curr= curr->next;
         }

          temp=list1;i=0;
           while( temp!= NULL){  
            if(i==b){
                break;
            }
             temp= temp->next;
             i++;
         }

         curr->next= temp->next;

         return dummy->next;

    }
};