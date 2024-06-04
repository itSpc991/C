// 链表
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 构造函数
Node *newNode (int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 初始化链表
Node *init(){
    Node* n0 = newNode(1);
    Node* n1 = newNode(2);
    Node* n2 = newNode(3);
    Node* n3 = newNode(4);
    Node* n4 = newNode(5);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
}

// 插入节点
void insert (Node *n0, Node *p){
    p->next = n0->next;
    n0->next = p;
}

// 删除节点
void delete (Node *n0){
    if (!n0 && !(n0->next)){
        return;
    }
    Node *p = n0->next;
    n0->next = n0->next->next;
    free(p);
}

// 访问节点
Node *find(Node *head, int index){
    for(int i = 0; i < index; i++) {
        if (head == NULL)
            return NULL;
        head = head->next;
    }
    return head;
}

//查找节点
/* 在链表中查找值为 target 的首个节点 */
int find(Node *head, int target) {
    int index = 0;
    while (head) {
        if (head->data == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    Node *head = init();
    return 0;
}
