#include <stdio.h>
#include <stdlib.h>

// LeetCode 預設的二元樹節點結構定義
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
*/

void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    // 只要當前節點不為空，就持續往下拉直
    while (curr != NULL) {
        // 如果當前節點有左子樹，才需要進行搬移與接線
        if (curr->left != NULL) {
            // 1. 尋找左子樹的「最右下角節點」
            struct TreeNode* predecessor = curr->left;
            while (predecessor->right != NULL) {
                predecessor = predecessor->right;
            }

            // 2. 將原本的右子樹，接到左子樹最右下角節點的後面
            predecessor->right = curr->right;

            // 3. 將整棵左子樹移到右邊，並清空左指標
            curr->right = curr->left;
            curr->left = NULL;
        }

        // 4. 移動到下一個節點（此時左邊已清空，直接往右走即可）
        curr = curr->right;
    }
}