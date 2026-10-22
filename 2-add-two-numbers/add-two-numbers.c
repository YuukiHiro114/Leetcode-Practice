#include <stdio.h>
#include <stdlib.h>

// LeetCode 預設的鏈結串列結構定義
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // 1. 建立虛擬頭節點，簡化指標操作
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    
    // current 指標用來不斷往後串接新節點
    struct ListNode* current = &dummy;
    int carry = 0; // 記錄進位

    // 2. 只要 l1、l2 其中一個還沒走完，或是還有進位值，就繼續相加
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry; // 當前的總和初始為前一次的進位值
        
        // 若 l1 還有節點，將其值加入並移動指標
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        // 若 l2 還有節點，將其值加入並移動指標
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // 3. 計算新的進位值與當前位數的數值
        carry = sum / 10;
        
        // 4. 配置新節點並串接
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        current->next = newNode;
        current = current->next;
    }
    
    // 5. 回傳虛擬頭節點的下一個節點（即實際解答的開頭）
    return dummy.next;
}