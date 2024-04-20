/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>


// 暴力解法 时间复杂度O(n^2)
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i=0; i<numsSize; i++) {
        for (int j=i+1; j<numsSize; j++){
            if( nums[i] + nums[j]==target ){
                *returnSize = 2;
                int* a = (int*)malloc(sizeof(int)*2);
                a[0] = i;
                a[1] = j;
                return a;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

//哈希表解法  时间复杂度O(1)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HashSize 108  //哈希表大小
typedef struct Node { // 哈希结点
    int value; // 值
    int index; // 下标
    struct Node* next; // 下指针
}Node;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int n = numsSize; // 数组长度
    Node* hash[HashSize]; // 哈希表
    for (int i = 0; i < HashSize; i++) { // 初始化哈希表
        hash[i] = (Node*)malloc(sizeof(Node));
        hash[i]->value = hash[i]->index = -1;
        hash[i]->next = NULL;
    }
    for (int i = 0; i < n; i++) { // 遍历一遍原数组
        int pos = abs(target - nums[i]) % HashSize; // 找到 target - nums[i] 在哈希表中对应的位置
        Node* head = hash[pos];
        while (head->next && head->next->value != target - nums[i]) head = head->next; // 找该位置是否有 target - nums[i] 这个值
        if (head->next) { // 找到符合题意的值
            *returnSize = 2;
            int* ans = (int*)malloc(sizeof(int) * 2);
            ans[0] = i; ans[1] = head->next->index; // 写入答案
            for (int i = 0; i < HashSize; i++) free(hash[i]);
            return ans;
        }
        pos = abs(nums[i]) % HashSize; // 找到 nums[i] 在哈希表中对应的位置
        head = hash[pos];
        while (head->next) head = head->next; // 写在这个位置的末尾
        head->next = (Node*)malloc(sizeof(Node));
        head->next->value = nums[i]; // 写入该值
        head->next->index = i; // 写入该值对应的下标
        head->next->next = NULL;
    }
    for (int i = 0; i < HashSize; i++) free(hash[i]);
    *returnSize = 0;
    return NULL;
}

