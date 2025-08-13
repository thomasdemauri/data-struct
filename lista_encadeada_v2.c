#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    int number;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int length;
} LinkedList;

LinkedList* createLinkedList();
void append(LinkedList *linkedList, int number);
void unshift(LinkedList *linkedList, int number);
void print(LinkedList *linkedList);
void pop(LinkedList *linkedList);
void shift(LinkedList *linkedList);

int main()
{

    LinkedList *list = createLinkedList();
    
    append(list, 10);
    append(list, 20);
    append(list, 60);

    printf("LinkedList (head) -> %d\n", list->head->number);
    printf("LinkedList (tail) -> %d\n", list->tail->number);

    unshift(list, 360);

    printf("LinkedList (head) -> %d\n", list->head->number);
    printf("LinkedList (tail) -> %d\n", list->tail->number);

    append(list, 456);

    print(list);

    printf("LinkedList (tail) -> %d\n", list->tail->number);

    pop(list);
    print(list);
    printf("After pop -> LinkedList (tail) -> %d\n", list->tail->number);

    shift(list);
    print(list);
    printf("After shift -> LinkedList (head) -> %d\n", list->head->number);


    return 0;
}

void shift(LinkedList *linkedList)
{
    if (linkedList == NULL) return;

    if (linkedList->head == NULL) return;

    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp = linkedList->head;

    linkedList->head = linkedList->head->next;

    free(tmp);
    tmp = NULL;

    return;

}

void pop(LinkedList *linkedList) 
{
    if (linkedList == NULL) return;

    if (linkedList->tail == NULL) return;

    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp = linkedList->tail;

    linkedList->tail = linkedList->tail->prev;

    free(tmp);
    tmp = NULL;
    
    linkedList->length--;
}


void unshift(LinkedList *linkedList, int number) 
{
    if (linkedList == NULL) return;

    Node *node = (Node*)malloc(sizeof(Node));

    node->number = number;

    linkedList->length++;
    
    // First element
    if (linkedList->head == NULL) {
        node->next = NULL;
        node->prev = NULL;
        linkedList->head = node;
        linkedList->tail = node;
        return;
    }

    node->next = linkedList->head;
    node->prev = NULL;

    node->next->prev = node;
    
    linkedList->head = node;

    return;
}

void append(LinkedList *linkedList, int number) 
{
    if (linkedList == NULL) return;

    Node *node = (Node*)malloc(sizeof(Node));
    
    node->next = NULL;
    node->number = number;

    linkedList->length++;

    // LinkedList has tail
    if (linkedList->tail != NULL) 
    {
        node->prev = linkedList->tail;
        linkedList->tail->next = node;
        linkedList->tail = node;

        return;
    }

    // First element
    if (linkedList->head == NULL) { 
    
        node->prev = NULL;
        linkedList->head = node;
        linkedList->tail = node;

        return;
    }
}

void print(LinkedList *linkedList)
{
    if (linkedList == NULL) return;

    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp = linkedList->head;

    while (tmp != NULL) {
        printf("%d ", tmp->number);
        tmp = tmp->next;
    }
    
    printf("\n");

    return;
}


LinkedList* createLinkedList()
{
    LinkedList *linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->length = 0;

    return linkedList;
}