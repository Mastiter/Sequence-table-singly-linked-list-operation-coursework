#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ��ʼ��������
void initLinkedList(Node** head) {
    *head = NULL;
}

// ���ɵ�����
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

// ��ӡ�������е�Ԫ��
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ͳ�Ƶ�����ĳ���
int getLinkedListLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// �ڵ������в���ָ�����ݵĽ��λ��
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

// ɾ���������������ظ����
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

// �ڵ������ָ��λ�ò���Ԫ��
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

    // ��ʼ��������
    initLinkedList(&head);

    // ���ɵ�����
    createLinkedList(&head);

    // ��ӡ�������е�Ԫ��
    printLinkedList(head);

    // ͳ�Ƶ�����ĳ���
    printf("Length of the list: %d\n", getLinkedListLength(head));

    // �ڵ������в���ֵΪ3�Ľ��
    i = searchLinkedList(head, 3);
    if (i == -1) {
        printf("Node with data 3 not found.\n");
    }
    else {
        printf("Node with data 3 found at position %d\n", i);
    }

    // �ڵ������в���ֵΪ7�Ľ��
    i = searchLinkedList(head, 7);
    if (i == -1) {
        printf("Node with data 7 not found.\n");
    }
    else {
        printf("Node with data 7 found at position %d\n", i);
    }

    // ɾ���������������ظ����
    deleteDuplicates(head);

    // ��ӡ�������е�Ԫ��
    printLinkedList(head);

    //�ڱ��е�i��λ�ò���ֵΪx��Ԫ��
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

    // ��ӡ�������е�Ԫ��
    printLinkedList(head);

    return 0;
}