// 数组
#include <stdio.h>
#include <stdlib.h>

#define Size 5

// 初始化数组
void init (int *nums, int size) {
    for (int i = 0; i < size; i++) {
        nums[i] = i;
    }
}

// 遍历数组
void traverse (int *nums, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
}

// 插入元素
void insert (int *nums, int size, int index, int value) {
    for (int i = size-1; i > index; i--)
    {       
        nums[i] = nums[i-1];
    }
    nums[index] = value;
}

// 删除元素
void delete (int *nums, int size, int index ){
    for(int i = index ; i < size; i++){
        nums[i-1] = nums[i];
    }
}

// 查找元素
int find(int *nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

// 数组扩容
int *expand(int *nums, int size, int enlargeSize) {
    int *newNums = (int*)malloc(size+enlargeSize);
    for (int i = 0; i < size; i++) {
        newNums[i] = nums[i];
    }
    for (int i = size; i < size+enlargeSize; i++) {
        newNums[i] = 0;
    }
    free(nums);
    return newNums;
}

int main(void) {
    int *nums = ((int*)malloc(sizeof(int)*Size));
    // init
    init(nums,5);
    // print
    traverse(nums, 5);
    printf("\n");
    // insert
    insert(nums, 5, 2, 9);
    traverse(nums, 5);
    printf("\n");
    //delete
    delete(nums, 5, 2);
    traverse(nums, 5);
    printf("\n");
    // find
    int i = find(nums, 5, 9);
    printf("%d\n",i);
    // expand
    traverse(expand(nums, 5, 2), 7);
    printf("\n");
}

