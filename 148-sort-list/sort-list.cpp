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
        if(!head || !head -> next)
            return head;
    ListNode* mid = getMiddle(head);
    ListNode* left = head;
    ListNode* right = mid -> next;
    mid -> next = nullptr;

    left = sortList(left);
    right = sortList(right);

    return merge(left, right);
    }
private:
    ListNode* getMiddle(ListNode*head){
        if(!head){
            return head;
        }
        ListNode*slow = head;
        ListNode*fast = head->next;
        while (fast && fast->next)
        {
            slow = slow -> next;
            fast = fast ->next->next;
        }
        return slow;
        }
        ListNode*merge(ListNode*left, ListNode*right){
            if(left==nullptr)return right;
            if(right==nullptr)return left;

            if(left->val<right->val){
                left->next = merge(left->next,right);
                return left;
            }
            else{
                right->next = merge(left,right->next);
                return right;
            }
            return nullptr;
        }
    };