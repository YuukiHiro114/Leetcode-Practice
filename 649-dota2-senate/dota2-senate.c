#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);

    // 配置兩個動態陣列來當作佇列 (Queue)
    int* radiant = (int*)malloc(n * sizeof(int));
    int* dire = (int*)malloc(n * sizeof(int));

    int r_head = 0, r_tail = 0; // radiant 佇列的頭尾指標
    int d_head = 0, d_tail = 0; // dire 佇列的頭尾指標

    // 1. 初始化：將兩派議員的初始索引分別存入對應佇列
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            radiant[r_tail++] = i;
        } else {
            dire[d_tail++] = i;
        }
    }

    // 2. 進行輪流禁言的比試
    while (r_head < r_tail && d_head < d_tail) {
        int r_index = radiant[r_head++]; // 取出 Radiant 最靠前的議員
        int d_index = dire[d_head++];   // 取出 Dire 最靠前的議員

        if (r_index < d_index) {
            // Radiant 議員先發言，禁言 Dire 議員
            // Radiant 議員獲得下一輪發言資格 (索引 + n)
            radiant[r_tail++] = r_index + n;
        } else {
            // Dire 議員先發言，禁言 Radiant 議員
            // Dire 議員獲得下一輪發言資格 (索引 + n)
            dire[d_tail++] = d_index + n;
        }
    }

    // 3. 判斷最終獲勝陣營
    bool radiant_win = (r_head < r_tail);

    // 釋放記憶體
    free(radiant);
    free(dire);

    return radiant_win ? "Radiant" : "Dire";
}