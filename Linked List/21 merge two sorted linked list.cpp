class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while(list1 && list2){
            if(list1->val<list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1){
            tail->next = list1;
        }else if(list2){
            tail->next = list2;
        }
        return dummy->next;
    }
};

//SC: O(1)
//TC: O(N)

/*
Notes:
start with dummy to avoid the edge case of inserting into an empty list.

*/