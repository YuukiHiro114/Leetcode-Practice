class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* newHead = new ListNode(0);
        ListNode* node = head;

        while (node != nullptr) {
            ListNode* next = node->next;
            ListNode* prevNode = newHead;
            ListNode* sortNode = newHead->next;

            while (sortNode != nullptr) {
                if (node->val > sortNode->val) {
                    prevNode = sortNode;
                    sortNode = sortNode->next;
                } else {
                    break;
                }
            }

            prevNode->next = node;
            node->next = sortNode;

            node = next;
        }

        ListNode* result = newHead->next;
        delete newHead; 
        return result;
    }
};