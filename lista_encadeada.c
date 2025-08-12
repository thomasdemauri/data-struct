#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    struct _node *next;
    int number;

} Node;

void append(Node **head, int number)
{
    Node *new = malloc(sizeof(Node));
    new->number = number;
    new->next = NULL;

    Node *tmp = *head;

    if (*head == NULL) {
        *head = new;
        return;
    }


    while (tmp->next != NULL) {
        tmp = tmp->next;
    }


    tmp->next = new;
    
    return;
}

// Remove last element
void pop(Node **head) {

    if (*head == NULL) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *tmp = *head;

    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    free(tmp->next);
    tmp->next = NULL;

}

// Remove first element
void shift(Node **head) {

    if (*head == NULL) return;

    Node *tmp = *head;

    if (tmp->next != NULL) {
        *head = tmp->next;
    } else {
        *head = NULL;
    }

    free(tmp);

}

void display(Node **head)
{
    Node *tmp = *head;

    while (tmp != NULL) {
        printf("%d ", tmp->number);
        tmp = tmp->next;
    }

    printf("\n");

}


int main()
{
    Node *head = malloc(sizeof(Node));
    head->number = 10;
    head->next = NULL;

    // append(&head, 26);
    // append(&head, 32);
    // append(&head, 46);
    // append(&head, 124);

    display(&head);

    // pop(&head);

    // display(&head);

    shift(&head);

    display(&head);

    return 0;
}