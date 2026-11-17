#include <stdio.h>
#include <stdlib.h>

// 題目預設的鏈結串列結構定義 (LeetCode 環境通常會自動提供)
/*
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

struct ListNode* swapPairs(struct ListNode* head) {
    // 1. 建立虛擬頭節點 dummy
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    // prev 指標用來記錄「要交換的兩個節點」的前一個位置
    struct ListNode* prev = &dummy;

    // 2. 只要 prev 後面還有至少兩個節點可以配對，就繼續交換
    while (prev->next != NULL && prev->next->next != NULL) {
        // 定義要交換的兩個節點
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;

        // 3. 執行交換指標的三個步驟
        first->next = second->next; // 步驟一：將 first 接上第二個節點之後的部分
        second->next = first;       // 步驟二：將 second 接上 first，完成兩者互換
        prev->next = second;        // 步驟三：將 prev 接上交換後排在前面的 second

        // 4. 移動 prev 指標，準備處理下一對
        prev = first; 
    }

    // 回傳新的頭節點（dummy 的下一個節點）
    return dummy.next;
}