#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len == 0)return 0;

    int*stack = (int*)malloc((len+1)*sizeof(int));//這裡宣告int是因為要計算長度，而長度要由index相減得到
    int top = 0;//top代表堆疊頂端下一個可放入的位置

    stack[top]=-1;//有-1的好處是能順利算出長度，而不會遇到pop之後堆疊空了，找不到能相減算位置的錨點
    top++;

    int max_len=0;//紀錄遇到的最長合法括號長度
    for(int i =0;i<len;i++){
        if(s[i]=='('){
            stack[top]=i;
            top++;
        }else{
            top--;
            if(top==0){
                stack[top]=i;//將當前無效右括號的位置i推進堆疊，作為後續計算長度的新基準線
                top++;
            }else{
                int current_len=i-stack[top-1];
                if(current_len>max_len){
                    max_len = current_len;
                }
            }
        }
    }
    free(stack);
    return max_len;
}
    