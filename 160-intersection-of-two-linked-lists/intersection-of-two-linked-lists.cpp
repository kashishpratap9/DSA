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
int getlen(ListNode* head){
     ListNode* temp= head;
     int len=0;
      while( temp!= NULL){
        len++;
         temp=temp->next;
      }
      return len;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1= getlen( headA);
        int len2= getlen( headB);
        ListNode* node1= headA;
        ListNode* node2=headB;
        if(len2>len1){
            int diff= len2-len1;
            int i=0;
            while(i<diff){
                i++;
                node2= node2->next;
            }

            while( node1!= node2){
                node1= node1->next;
                 node2= node2->next;
            }
            return node1;

        }else{
            int diff= len1-len2;
            int i=0;
            while(i<diff){
                i++;
                node1= node1->next;
            }

            while( node1!= node2){
                node1= node1->next;
                node2= node2->next;
            }
             return node1;

        }

        return NULL;
      
        
    }
};