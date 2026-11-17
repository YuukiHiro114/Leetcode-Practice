#include <stdlib.h>
#include <string.h>

// 遞迴輔助函式，處理特定區間的運算式
int* computeHelper(char* expression, int start, int end, int* returnSize) {
    // 題目保證結果數量不會超過 10^4，這裡配置足夠的記憶體空間
    int* res = (int*)malloc(8000 * sizeof(int));
    int resSize = 0;
    int hasOperator = 0; // 用來標記此區間內是否有運算符號

    // 走訪當前區間內的每一個字元
    for (int i = start; i <= end; i++) {
        char c = expression[i];
        // 如果遇到運算符號，以此符號為中心進行切割
        if (c == '+' || c == '-' || c == '*') {
            hasOperator = 1;
            int leftSize = 0, rightSize = 0;
            
            // 遞迴計算左半邊的所有可能結果
            int* leftRes = computeHelper(expression, start, i - 1, &leftSize);
            // 遞迴計算右半邊的所有可能結果
            int* rightRes = computeHelper(expression, i + 1, end, &rightSize);

            // 將左右兩邊的結果進行兩兩組合運算
            for (int j = 0; j < leftSize; j++) {
                for (int k = 0; k < rightSize; k++) {
                    if (c == '+') {
                        res[resSize++] = leftRes[j] + rightRes[k];
                    } else if (c == '-') {
                        res[resSize++] = leftRes[j] - rightRes[k];
                    } else if (c == '*') {
                        res[resSize++] = leftRes[j] * rightRes[k];
                    }
                }
            }
            // 釋放左右子陣列的記憶體，避免 Memory Leak
            free(leftRes);
            free(rightRes);
        }
    }

    // 如果區間內沒有任何運算符號，代表它是一個純數字
    if (!hasOperator) {
        int num = 0;
        for (int i = start; i <= end; i++) {
            num = num * 10 + (expression[i] - '0');
        }
        res[resSize++] = num; // 將解析出的數字存入結果陣列
    }

    // 更新回傳陣列的大小
    *returnSize = resSize;
    return res;
}

int* diffWaysToCompute(char * expression, int* returnSize) {
    // 呼叫輔助函式，處理整個字串 (從索引 0 到字串結尾)
    return computeHelper(expression, 0, strlen(expression) - 1, returnSize);
}