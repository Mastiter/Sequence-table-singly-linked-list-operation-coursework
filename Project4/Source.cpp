#include <stdio.h>
#include <stdlib.h>

// 定义单链表结点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 初始化一个空链表
void initLinkedList(Node** head) {
    *head = NULL;
}

// 生成一个带头结点的单链表
void createLinkedList(Node** head) {
    int value;
    Node* tail = NULL;

    printf("Enter the elements of the linked list (enter -100 to exit):\n");
    while (1) {
        if (scanf_s("%d", &value) != 1) {
            printf("Invalid input\n");
            exit(1);
        }

        if (value == -100) {
            break;
        }

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

// 统计单链表的长度
int getLinkedListLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
            count++;
        current = current->next;
    }
    return count;
}

// 在单链表中查找值为x的结点，返回结点序号（若查找失败则返回 -1）
#include <cstdlib>

void releaseMemory(int* indices) {
    free(indices);
}

int* findNode(Node* head, int x) {
    int index = 0;
    Node* current = head;
    int* indices = NULL;  // 动态分配的整数数组
    int size = 0;  // 数组的大小

    while (current != NULL) {
        if (current->data == x) {
            // 扩展数组大小
            int* temp = (int*)realloc(indices, (size + 1) * sizeof(int));
            if (temp == NULL) {
                releaseMemory(indices);
                return NULL;  // 内存分配失败
            }
            indices = temp;
            indices[size] = index;
            size++;
        }
        index++;
        current = current->next;
    }

    // 在数组的末尾添加一个标记，以指示数组的结束
    int* temp = (int*)realloc(indices, (size + 1) * sizeof(int));
    if (temp == NULL) {
        releaseMemory(indices);
        return NULL;  // 内存分配失败
    }
    indices = temp;
    indices[size] = -1;

    return indices;
}

// 删除单链表中相邻重复结点
void removeDuplicates(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else {
            current = current->next;
        }
    }
}

// 在单链表的第i个位置插入一个值为x的元素
void insertNode(Node** head, int i, int x) {
    if (i < 0) {
        printf("Invalid position\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (i == 0) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        Node* current = *head;
        int count = 0;
        while (count < i - 1 && current != NULL) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Invalid position\n");
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 打印单链表中的各个结点元素
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head;
    int i, x;

    // 初始化一个空链表
    initLinkedList(&head);

    // 生成一个带头结点的单链表
    createLinkedList(&head);

    // 打印各结点元素
    printf("Linked list elements: ");
    printLinkedList(head);

    // 统计表长（数据结点个数）
    int length = getLinkedListLength(head);
    printf("Length of the list: %d\n", length);

    // 在表中查找数据为3的结点，打印查找结果
    int* indices = findNode(head, 3);
    if (indices != NULL) {
        int i = 0;
        if (indices[i] != -1) {
            while (indices[i] != -1) {
                printf("Node with data 3 found at index: %d\n", indices[i]);    // 使用 indices[i] 获取索引的值
                i++;
            }
        }else {
            printf("Node with data 3 not found\n");
        }
        releaseMemory(indices);  // 释放动态分配的内存
    }
   

    // 在表中查找数据为7的结点，打印查找结果
    indices = findNode(head, 7);
    if (indices != NULL) {
        int i = 0;
        if (indices[i] != -1) {
            while (indices[i] != -1) {
                printf("Node with data 7 found at index: %d\n", indices[i]);    // 使用 indices[i] 获取索引的值
                i++;
            }
        }
        else {
            printf("Node with data 7 not found\n");
        }
        releaseMemory(indices);  // 释放动态分配的内存
    }

    //对当前单链表执行删除相邻重复结点的操作
    removeDuplicates(head);

    // 打印各结点元素
    printf("Linked list elements after removing duplicates: ");
    printLinkedList(head);

    // 在表中第i个位置插入值为x的元素
    printf("Enter the position to insert: ");
    if (scanf_s("%d", &i) != 1) {
        printf("Invalid input\n");
        exit(1);
    }
    printf("Enter the value to insert: ");
    if (scanf_s("%d", &x) != 1) {
        printf("Invalid input\n");
        exit(1);
    }
    insertNode(&head, i, x);

    // 打印各结点元素
    printf("Linked list elements after insertion: ");
    printLinkedList(head);

    // 释放单链表的内存
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}