#include <stdio.h>
#include <stdlib.h>

// 題目預設的二元樹節點結構 (LeetCode 環境會自動提供)
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
*/

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    // 1. 初始化回傳的層數為 0
    *returnSize = 0;
    
    // 2. 邊界條件：如果樹是空的，配置空陣列並直接回傳
    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // 3. 配置回傳用的二維陣列與記錄每層長度的陣列 (題目限制節點最多 2000 個，層數最多 2000 層)
    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    // 4. 建立一個簡易的陣列佇列 (Queue) 來存放樹節點指標
    struct TreeNode* queue[2000];
    int front = 0; // 佇列前端索引（負責取出節點）
    int rear = 0;  // 佇列尾端索引（負責放入節點）

    // 5. 將根節點放入佇列，開始 BFS
    queue[rear++] = root;

    // 6. 只要佇列裡還有節點，就代表還有層級沒走完
    while (front < rear) {
        // 計算當前這一層總共有幾個節點
        int levelSize = rear - front;
        
        // 記錄這一層的節點數量，並為這一層配置一維陣列空間
        (*returnColumnSizes)[*returnSize] = levelSize;
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));

        // 7. 依序取出當前這一層的所有節點
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = queue[front++]; // 從佇列前端取出節點
            result[*returnSize][i] = current->val;     // 存入當前層級的陣列中

            // 如果有左子節點，排入佇列尾端（給下一層使用）
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
            // 如果有右子節點，排入佇列尾端（給下一層使用）
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }

        // 8. 當前層級處理完畢，總層數加 1
        (*returnSize)++;
    }

    return result;
}