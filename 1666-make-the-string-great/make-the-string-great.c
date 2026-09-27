#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char* makeGood(char* s) {
    int len = strlen(s);//取得字串s的長度
    char* stack = (char*)malloc((len+1)*sizeof(char));//len+1是因為結尾需要/0
    int top = 0;

    for(int i=0 ; i<len ; i++){
        if (top>0 && abs(stack [top-1]-s[i])==32){//abs是取絕對值
            top--;//堆疊頂端的字元pop掉
        }else{
            stack[top] = s[i];
            top++;
        }
        }
    stack[top] = '\0';//在結果字串補上結束符號
    return stack;
    }
