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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // count length
        int n = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            n++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        for (int size = 1; size < n; size *= 2) {
            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;

            while (curr != NULL) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);
                prev = merge(left, right, prev);
            }
        }

        return dummy.next;
    }

private:
    // splits off 'size' nodes from head, returns start of remaining list
    ListNode* split(ListNode* head, int size) {
        for (int i = 1; head != NULL && i < size; i++) {
            head = head->next;
        }
        if (head == NULL) return NULL;
        ListNode* second = head->next;
        head->next = NULL;
        return second;
    }

    // merges two sorted lists, attaches to prev, returns new tail
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prev) {
        ListNode* curr = prev;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 != NULL) ? l1 : l2;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        return curr;
    }
};