class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {
            ListNode* kThNode = getKthNode(temp, k);
            if (kThNode == NULL) {
                // fewer than k nodes left, leave as-is
                if (prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;

            reverseLinkedList(temp);

            if (temp == head) {
                head = kThNode;
            } else {
                prevLast->next = kThNode;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }

private:
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    void reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
    }
};