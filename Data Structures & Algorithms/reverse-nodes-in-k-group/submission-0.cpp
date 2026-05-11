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

    // Find kth node from current position
    ListNode* getKthNode(ListNode* curr, int k) {

        while (curr != nullptr && k > 0) {

            curr = curr->next;
            k--;
        }

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {

            // Find kth node
            ListNode* kth = getKthNode(groupPrev, k);

            // Not enough nodes
            if (kth == nullptr)
                break;

            ListNode* groupNext = kth->next;

            // Reverse group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {

                ListNode* temp = curr->next;

                curr->next = prev;

                prev = curr;
                curr = temp;
            }

            // Connect reversed group
            ListNode* temp = groupPrev->next;

            groupPrev->next = kth;

            groupPrev = temp;
        }

        return dummy.next;
    }
};
