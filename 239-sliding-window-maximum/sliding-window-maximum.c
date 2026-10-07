#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    // 根據題目設定，nums 長度與 k 至少為 1，但實務上加上防呆機制更佳
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    // 計算結果陣列的長度
    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    
    // 使用陣列模擬雙向佇列 (Deque)，用來存放 nums 的「索引值」
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int front = 0;      // 佇列最前端
    int rear = -1;      // 佇列最尾端

    for (int i = 0; i < numsSize; i++) {
        // 1. 移除已經滑出當前視窗外的索引
        // 當前視窗範圍是 [i - k + 1, i]，若前端索引小於 i - k + 1 代表已過期
        if (front <= rear && deque[front] < i - k + 1) {
            front++; 
        }

        // 2. 保持佇列的單調遞減性
        // 如果新進來的 nums[i] 大於等於佇列尾端索引所對應的數值，
        // 就將尾端元素剔除，因為它們不可能再成為最大值了。
        while (front <= rear && nums[deque[rear]] <= nums[i]) {
            rear--;
        }

        // 3. 將當前元素的索引加入佇列尾端
        rear++;
        deque[rear] = i;

        // 4. 當視窗的右邊界 i 達到或超過 k - 1 時，視窗才成型，開始記錄最大值
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[front]];
        }
    }

    // 釋放模擬佇列所使用的記憶體
    free(deque);
    
    return result;
}