#include <stdio.h>
#include <stdlib.h>

// 題目預設的鏈結串列結構 (LeetCode 環境通常會自動提供)
/*
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    // 建立虛擬頭節點 dummy
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    // prevGroupEnd 用來記錄「準備要反轉的 k 個節點」的前一個位置
    struct ListNode* prevGroupEnd = &dummy;

    while (1) {
        // 1. 檢查是否還有至少 k 個節點可以反轉
        struct ListNode* kthNode = prevGroupEnd;
        for (int i = 0; i < k; i++) {
            kthNode = kthNode->next;
            // 如果不足 k 個節點，代表處理完畢，直接回傳結果
            if (kthNode == NULL) {
                return dummy.next;
            }
        }

        // 2. 記錄這組 k 個節點的下一個起點，方便反轉後接回剩餘串列
        struct ListNode* nextGroupStart = kthNode->next;

        // 3. 準備進行這 k 個節點的反轉
        // prev 初始化為 nextGroupStart，這樣反轉後的第一個節點就會自動連向後面的串列
        struct ListNode* prev = nextGroupStart; 
        struct ListNode* curr = prevGroupEnd->next;
        struct ListNode* groupStart = curr; // 記錄這組的原始頭部（反轉後會變成尾部）

        // 執行 k 次反轉操作
        for (int i = 0; i < k; i++) {
            struct ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // 4. 將前一個區段的尾巴，接上這次反轉後的新頭部 (即現在的 prev)
        prevGroupEnd->next = prev;

        // 5. 更新 prevGroupEnd 到這組反轉後的新尾部，準備處理下一組
        prevGroupEnd = groupStart;
    }

    return dummy.next;
}