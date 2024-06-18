class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }
        
        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
            }
            n = (n + 1) / 2;
        }
        
        return lists.front();
    }
    private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        
        ListNode* head = NULL;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        ListNode* curr = head;
        
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        if (list1 == NULL) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }
        
        return head;
    }
};

//TC: O(Nlogk)
//SC: O(N)

//Gpt notes

/*
To analyze the time complexity of the given code, we need to break down the two main parts: the `mergeKLists` function and the `mergeTwoLists` function.

### `mergeTwoLists` Function

The `mergeTwoLists` function merges two sorted linked lists. The time complexity of merging two lists of lengths \(m\) and \(n\) is \(O(m + n)\), as each element from both lists is visited exactly once.

### `mergeKLists` Function

The `mergeKLists` function merges \(k\) sorted linked lists by repeatedly pairing and merging them.

1. **Initial Size of Lists**: Let \(k\) be the number of linked lists.
2. **First Merge Step**: In the first pass, each pair of lists is merged.
   - Number of merges: \(\frac{k}{2}\)
   - Each merge involves lists of various sizes, but in the worst case, merging two lists of total size \(N\) (where \(N\) is the total number of nodes across all lists).

3. **Subsequent Merge Steps**:
   - After the first pass, the number of lists is halved (or halved and rounded up).
   - This halving continues until only one list remains.
   - The number of merge steps is \(\log k\) (since the number of lists is halved each time).

### Total Complexity Analysis

In each merge step, we are effectively merging a total of \(N\) nodes, but the number of lists being merged reduces exponentially.

- In the first pass, there are \(\frac{k}{2}\) merges.
- In the second pass, there are \(\frac{k}{4}\) merges.
- This continues until there is only one list left.

Thus, the total time complexity involves \(\log k\) merge steps, each processing \(N\) nodes in total.

\[
\text{Total Time Complexity} = O(N \log k)
\]

Here:
- \(N\) is the total number of nodes across all \(k\) linked lists.
- \(\log k\) is the number of levels of merging.

Therefore, the overall time complexity of the `mergeKLists` function is \(O(N \log k)\).
*/