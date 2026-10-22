#include <stdio.h>
#include <stdlib.h>

// LeetCode 預設的鏈結串列結構定義
/*
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

struct ListNode* insertionSortList(struct ListNode* head) {
    // 若串列為空或只有一個節點，不需排序直接回傳
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode dummy; // 虛擬頭節點，作為排序後串列的起點
    dummy.next = NULL;
    
    struct ListNode* current = head; // current 用來走訪原串列的每一個節點

    // 不斷處理，直到沒有輸入元素剩餘
    while (current != NULL) {
        // 先記錄下一個要處理的節點，避免改變 current->next 時斷鏈
        struct ListNode* next_node = current->next;
        
        // 每次插入都從已排序串列的頭部 (dummy) 開始尋找合適的位置
        struct ListNode* prev = &dummy;
        
        // 尋找插入點：只要 prev 的下一個節點的值小於 current->val，就繼續往後找
        while (prev->next != NULL && prev->next->val < current->val) {
            prev = prev->next;
        }
        
        // 將 current 節點插入到 prev 和 prev->next 之間
        current->next = prev->next;
        prev->next = current;
        
        // 移動到原串列的下一個節點繼續處理
        current = next_node;
    }

    // 回傳排序好的串列頭部
    return dummy.next;
}