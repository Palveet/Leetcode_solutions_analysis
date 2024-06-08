class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr!=NULL){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr= temp;
        }
        return prev;
    }
};

//TC: O(N)
//SC: O(1)

/*
Algo notes:

1. a prev pointer is initialized which eventually becomes the head and is returned at the end;
2. current's next pointer is reversed and pointed to previous (actual reversal step).
3. before breaking the link, current's next is stored in temp.
4. previous becomes current.
5. current becomes temp
6. all this is performed till current is not pointing to null.
7. return previous.
*/