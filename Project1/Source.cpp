#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 初始化单链表
void initLinkedList(Node** head) {
    *head = NULL;
}

// 生成单链表
void createLinkedList(Node** head) {
    int length;
    int value;

    printf("Enter the length of the linked list: ");
    if (scanf_s("%d", &length) != 1) {
        printf("Invalid input\n");
        exit(1);
    }

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < length; i++) {
        if (scanf_s("%d", &value) != 1) {
            printf("Invalid input\n");
            exit(1);
        }

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        }
        else {
            Node* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

// 打印单链表中的元素
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
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

// 在单链表中查找指定数据的结点位置
int searchLinkedList(Node* head, int data) {
    int position = 1;
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1;
}

// 删除单链表中相邻重复结点
void deleteDuplicates(Node* head) {
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

// 在单链表的指定位置插入元素
void insertLinkedList(Node* head, int position, int value) {
    if (position < 1 || position > getLinkedListLength(head) + 1) {
        printf("Invalid position\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    Node* head;
    int i, x;

    // 初始化单链表
    initLinkedList(&head);

    // 生成单链表
    createLinkedList(&head);

    // 打印单链表中的元素
    printLinkedList(head);

    // 统计单链表的长度
    printf("Length of the list: %d\n", getLinkedListLength(head));

    // 在单链表中查找值为3的结点
    i = searchLinkedList(head, 3);
    if (i == -1) {
        printf("Node with data 3 not found.\n");
    }
    else {
        printf("Node with data 3 found at position %d\n", i);
    }

    // 在单链表中查找值为7的结点
    i = searchLinkedList(head, 7);
    if (i == -1) {
        printf("Node with data 7 not found.\n");
    }
    else {
        printf("Node with data 7 found at position %d\n", i);
    }

    // 删除单链表中相邻重复结点
    deleteDuplicates(head);

    // 打印单链表中的元素
    printLinkedList(head);

    //在表中第i个位置插入值为x的元素
    printf("Enter the position to insert an element: ");
    if (scanf_s("%d", &i) != 1) {
        printf("Invalid input\n");
        exit(1);
    }

    printf("Enter the element to insert: ");
    if (scanf_s("%d", &x) != 1) {
        printf("Invalid input\n");
        exit(1);
    }

    insertLinkedList(head, i, x);

    // 打印单链表中的元素
    printLinkedList(head);

    return 0;
}