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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> nodesInB;
        while(headB!=NULL){
            nodesInB.insert(headB);
            headB=headB->next;
        }
        while(headA!=NULL){
            if(nodesInB.find(headA)!=nodesInB.end()){
                return headA;
            }
            headA=headA->next;
        }
        return NULL;
    }
};

//TC:O(M+N)
//SC:O(M)