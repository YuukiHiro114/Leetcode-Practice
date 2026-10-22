#include <stdio.h>
#include <stdlib.h>

// 題目預設的鏈結串列結構 (LeetCode 環境通常會自動提供)
/*
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

// 輔助函式：合併兩個排序好的鏈結串列
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;      // 虛擬頭節點
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode* current = &dummy;

    // 比較兩個串列的節點，將較小的值接在 current 後面
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // 若其中一個串列已經走完，將另一個剩下的部分直接接上
    if (l1 != NULL) {
        current->next = l1;
    }
    if (l2 != NULL) {
        current->next = l2;
    }

    return dummy.next;
}

// 主函式：合併 k 個排序好的鏈結串列
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    // 若陣列為空，依照題目範例 2 直接回傳空結果
    if (listsSize == 0) {
        return NULL;
    }
    
    // interval 代表兩兩合併時，兩個串列在陣列中的間距
    int interval = 1;
    
    // 當間距小於陣列長度時，繼續進行分治合併
    while (interval < listsSize) {
        // 每次跳跃 interval * 2 的距離，將相鄰的兩個串列合併
        for (int i = 0; i + interval < listsSize; i += interval * 2) {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        // 每完成一輪合併，間距倍增
        interval *= 2;
    }
    
    // 所有的結果最終都會被合併並存放到 lists[0] 中
    return lists[0];
}