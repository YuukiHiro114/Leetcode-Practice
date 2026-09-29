#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    int len = strlen (path);
    char**stack = (char**)malloc(len*sizeof(char*));

    char*token = strtok(path,"/");//strtok是C語言切割字串的函式。它會把遇到的不是/的子字串位址回傳給token
    int top=0;

    while (token!=NULL){
        if(strcmp(token,".")==0){//strcmp比較兩個字串是否相同，是.就不用做任何處理
        }else if(strcmp(token,"..")==0){
            if(top>0){
                top--;
            }
    }else{
        //不是.也不是..，所以是一般資料夾名稱，push進堆疊
        stack[top]=token;
        top++;
    }
    token = strtok(NULL,"/");
    }
    if (top==0){
        free(stack);
        char* result = (char*)malloc(2*sizeof(char));//配置2bytes的記憶體空間是因為包含斜線'/'與字串結尾符號'\0'兩個字元
        strcpy(result,"/");//將'/'與'\0'填入配置好的result記憶體空間
        return result;
    }
    //top==0不成立時執行下方程式碼
    char* result = (char*)malloc((len+1)*sizeof(char));
    result[0] = '\0';//result初始化為一個長度為0的空字串

    //將stack中的資料夾名稱依序用'/'串接起來

    for(int i=0;i<top;i++){
        strcat(result,"/");//strcat會從result的開頭開始找'\0'，找到後會把"/"的內容覆蓋寫入從'\0'開始的位置
        strcat(result,stack[i]);//假設上一行的result是result[0]，這一行就是result[1]
    }
    free(stack);
    return result;
    
}