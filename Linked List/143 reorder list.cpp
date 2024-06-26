class Solution {
public:
    void reorderList(ListNode* head) {
        if (head->next == NULL) {
            return;
        }

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);

        merge(l1, l2);
    }
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void merge(ListNode* l1, ListNode* l2) {
        while (l1 != NULL) {
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;

            l1->next = l2;
            if (p1 == NULL) {
                break;
            }
            l2->next = p1;

            l1 = p1;
            l2 = p2;
        }
    }
};

//TC: O(N)
//SC: O(1)