#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LeetCode 預設的二元樹節點結構定義
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
*/

// 序列化輔助函式：利用前序遍歷將節點寫入字串緩衝區
void serializeHelper(struct TreeNode* root, char* buffer, int* pos) {
    // 1. 基礎條件：遇到空節點時，寫入 "#," 作為標記
    if (root == NULL) {
        *pos += sprintf(buffer + *pos, "#,");
        return;
    }

    // 2. 寫入當前節點的數值與逗號，並更新寫入位置 pos
    *pos += sprintf(buffer + *pos, "%d,", root->val);

    // 3. 遞迴處理左子樹與右子樹
    serializeHelper(root->left, buffer, pos);
    serializeHelper(root->right, buffer, pos);
}

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    // 題目限制節點最多 10^4 個，每個節點連同符號與空子樹標記約佔 10 字元，配置 150000 bytes 絕對足夠
    char* buffer = (char*)malloc(150000 * sizeof(char));
    int pos = 0; // 記錄目前字串寫入到哪個索引位置

    serializeHelper(root, buffer, &pos);
    buffer[pos] = '\0'; // 加上 C 語言字串結尾符號

    return buffer;
}

// 反序列化輔助函式：透過指標的指標推進字串讀取進度
struct TreeNode* deserializeHelper(char** dataPtr) {
    // 如果已經讀到字串結尾，直接回傳 NULL
    if (*dataPtr == NULL || **dataPtr == '\0') {
        return NULL;
    }

    // 1. 尋找下一個逗號的位置，切出當前的數值或 '#' 標記
    char* comma = strchr(*dataPtr, ',');
    if (comma != NULL) {
        *comma = '\0'; // 將逗號暫時替換為字串結尾，方便解析當前片段
    }

    // 2. 如果當前片段是 "#"，代表這是空節點
    if (strcmp(*dataPtr, "#") == 0) {
        // 將讀取指標推進到逗號的下一個字元，並回傳 NULL
        *dataPtr = (comma != NULL) ? (comma + 1) : NULL;
        return NULL;
    }

    // 3. 將字串轉為整數，並建立新的樹節點
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = atoi(*dataPtr);

    // 將讀取指標推進到下一個片段的開頭
    *dataPtr = (comma != NULL) ? (comma + 1) : NULL;

    // 4. 依照「左 -> 右」的順序遞迴建立子樹
    node->left = deserializeHelper(dataPtr);
    node->right = deserializeHelper(dataPtr);

    return node;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    // 傳入 data 指標的位址，讓遞迴過程中所有層級都能同步推進讀取位置
    return deserializeHelper(&data);
}