#include <stdio.h>
#include <stdlib.h>

// ���嵥������
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ��ʼ��һ��������
void initLinkedList(Node** head) {
    *head = NULL;
}

// ����һ����ͷ���ĵ�����
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

// �ڵ������в���ֵΪx�Ľ�㣬���ؽ����ţ�������ʧ���򷵻� -1��
#include <cstdlib>

void releaseMemory(int* indices) {
    free(indices);
}

int* findNode(Node* head, int x) {
    int index = 0;
    Node* current = head;
    int* indices = NULL;  // ��̬�������������
    int size = 0;  // ����Ĵ�С

    while (current != NULL) {
        if (current->data == x) {
            // ��չ�����С
            int* temp = (int*)realloc(indices, (size + 1) * sizeof(int));
            if (temp == NULL) {
                releaseMemory(indices);
                return NULL;  // �ڴ����ʧ��
            }
            indices = temp;
            indices[size] = index;
            size++;
        }
        index++;
        current = current->next;
    }

    // �������ĩβ���һ����ǣ���ָʾ����Ľ���
    int* temp = (int*)realloc(indices, (size + 1) * sizeof(int));
    if (temp == NULL) {
        releaseMemory(indices);
        return NULL;  // �ڴ����ʧ��
    }
    indices = temp;
    indices[size] = -1;

    return indices;
}

// ɾ���������������ظ����
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

// �ڵ�����ĵ�i��λ�ò���һ��ֵΪx��Ԫ��
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

// ��ӡ�������еĸ������Ԫ��
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

    // ��ʼ��һ��������
    initLinkedList(&head);

    // ����һ����ͷ���ĵ�����
    createLinkedList(&head);

    // ��ӡ�����Ԫ��
    printf("Linked list elements: ");
    printLinkedList(head);

    // ͳ�Ʊ������ݽ�������
    int length = getLinkedListLength(head);
    printf("Length of the list: %d\n", length);

    // �ڱ��в�������Ϊ3�Ľ�㣬��ӡ���ҽ��
    int* indices = findNode(head, 3);
    if (indices != NULL) {
        int i = 0;
        if (indices[i] != -1) {
            while (indices[i] != -1) {
                printf("Node with data 3 found at index: %d\n", indices[i]);    // ʹ�� indices[i] ��ȡ������ֵ
                i++;
            }
        }else {
            printf("Node with data 3 not found\n");
        }
        releaseMemory(indices);  // �ͷŶ�̬������ڴ�
    }
   

    // �ڱ��в�������Ϊ7�Ľ�㣬��ӡ���ҽ��
    indices = findNode(head, 7);
    if (indices != NULL) {
        int i = 0;
        if (indices[i] != -1) {
            while (indices[i] != -1) {
                printf("Node with data 7 found at index: %d\n", indices[i]);    // ʹ�� indices[i] ��ȡ������ֵ
                i++;
            }
        }
        else {
            printf("Node with data 7 not found\n");
        }
        releaseMemory(indices);  // �ͷŶ�̬������ڴ�
    }

    //�Ե�ǰ������ִ��ɾ�������ظ����Ĳ���
    removeDuplicates(head);

    // ��ӡ�����Ԫ��
    printf("Linked list elements after removing duplicates: ");
    printLinkedList(head);

    // �ڱ��е�i��λ�ò���ֵΪx��Ԫ��
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

    // ��ӡ�����Ԫ��
    printf("Linked list elements after insertion: ");
    printLinkedList(head);

    // �ͷŵ�������ڴ�
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}