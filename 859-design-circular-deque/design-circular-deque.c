#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* buffer;    // 儲存資料的動態陣列
    int front;      // 指向前端元素的索引
    int capacity;   // 佇列最大容量 (k)
    int size;       // 目前已儲存的元素數量
} MyCircularDeque;

// 初始化雙端佇列，設定最大容量為 k
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->buffer = (int*)malloc(k * sizeof(int));
    obj->front = 0;
    obj->capacity = k;
    obj->size = 0;
    return obj;
}

// 檢查佇列是否為空
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

// 檢查佇列是否已滿
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

// 從佇列前端插入元素
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    // front 逆時針往前移動一格（加上 capacity 避免負數取模問題）
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->buffer[obj->front] = value;
    obj->size++;
    return true;
}

// 從佇列尾端插入元素
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    // 計算尾端新元素應放置的位置
    int rearIndex = (obj->front + obj->size) % obj->capacity;
    obj->buffer[rearIndex] = value;
    obj->size++;
    return true;
}

// 從佇列前端刪除元素
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }
    // front 順時針往後移動一格
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

// 從佇列尾端刪除元素
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }
    // 將元素數量減 1 即可，下次插入尾端時會直接覆蓋
    obj->size--;
    return true;
}

// 取得前端元素
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }
    return obj->buffer[obj->front];
}

// 取得尾端元素
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }
    // 計算尾端最後一個有效元素的索引
    int rearIndex = (obj->front + obj->size - 1) % obj->capacity;
    return obj->buffer[rearIndex];
}

// 釋放記憶體
void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->buffer);
    free(obj);
}