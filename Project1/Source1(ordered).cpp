#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

// ��ʼ��˳���
void initSeqList(SeqList* list) {
    list->length = 0;
}

// ��˳���ֵ
void assignSeqList(SeqList* list) {
    int i;
    printf("Enter the number of elements: ");
    if (scanf_s("%d", &(list->length)) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
    printf("Enter the elements: ");
    for (i = 0; i < list->length; i++) {
        if (scanf_s("%d", &(list->data[i])) != 1) {
            printf("Invalid input.\n");
            exit(1);
        }
    }
}

// ɾ��˳����е�i��Ԫ��
int deleteSeqList(SeqList* list, int i) {
    int j;
    if (i < 1 || i > list->length) {
        printf("Invalid position.\n");
        return 0;
    }
    for (j = i; j < list->length; j++) {
        list->data[j - 1] = list->data[j];
    }
    list->length--;
    return 1;
}

// ��ӡ˳����е�Ԫ��
void printSeqList(SeqList* list) {
    int i;
    printf("Elements in the list: ");
    for (i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// ��˳���ĵ�i��λ�ò���Ԫ��x
int insertSeqList(SeqList* list, int i, int x) {
    int j;
    if (i < 1 || i > list->length + 1) {
        printf("Invalid position.\n");
        return 0;
    }
    if (list->length >= MAX_SIZE) {
        printf("List is full.\n");
        return 0;
    }
    for (j = list->length; j >= i; j--) {
        list->data[j] = list->data[j - 1];
    }
    list->data[i - 1] = x;
    list->length++;
    return 1;
}

// ɾ��˳���������ֵΪ����Ԫ��
void deleteNegativeElements(SeqList* list) {
    int i, j;
    j = 0;
    for (i = 0; i < list->length; i++) {
        if (list->data[i] >= 0) {
            list->data[j] = list->data[i];
            j++;
        }
    }
    list->length = j;
}

int main() {
    SeqList list;
    int i, x;

    // ��ʼ��˳���
    initSeqList(&list);

    // ��˳���ֵ
    assignSeqList(&list);

    // ��ӡ˳����е�Ԫ��
    printSeqList(&list);

    // ɾ�����еĵ�i��Ԫ��
    printf("Enter the position to delete an element: ");
    if (scanf_s("%d", &i) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
    deleteSeqList(&list, i);

    // ��ӡ˳����е�Ԫ��
    printSeqList(&list);

    // ��˳���ĵ�i��λ�ò���һ��Ԫ��x
    printf("Enter the position to insert an element: ");
    if (scanf_s("%d", &i) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
    printf("Enter the element to insert: ");
    if (scanf_s("%d", &x) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
    insertSeqList(&list, i, x);

    // ��ӡ˳����е�Ԫ��
    printSeqList(&list);

    // ɾ��С��0��Ԫ��
    deleteNegativeElements(&list);

    // ��ӡ˳����е�Ԫ��
    printSeqList(&list);

    return 0;
}