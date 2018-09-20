#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int position;
    struct node *next;
} Node;

void insert(Node** head, int newPosition);
void delete(Node** head, int newPosition);
void printList(Node* head);

int main(void){
    Node *head = NULL;

    int peopleIN;
    scanf("%d", &peopleIN);
    while (peopleIN--){
        int newPosition;
        scanf("%d", &newPosition);
        insert(&head, newPosition);
    };

    int peopleOUT;
    scanf("%d", &peopleOUT);
    while (peopleOUT--){
        int newPosition;
        scanf("%d", &newPosition);
        delete(&head, newPosition);
    };

    printList(head);
    printf("\n");
    return 0;
}

void insert(Node** head, int newPosition){
    Node *current = (Node *)malloc(sizeof(Node));
    current->position = newPosition;
    current->next = NULL;

    if(*head == NULL){
        *head = current;
        return;
    } else {
        Node *tail = *head;
        while(tail->next)
            tail = tail->next;
        tail->next = current;
    }
}

void delete(Node** head, int newPosition){
    Node *pointer = *head, *prev;
    if (pointer == NULL)
        return;
    if (pointer->position == newPosition){
        *head = pointer->next;
        free(pointer);
        return;
    }
    while (pointer->position != newPosition){
        prev = pointer;
        pointer = pointer->next;
    }
    prev->next = pointer->next;
    free(pointer);
}

void printList(Node* head){
    while (head != NULL){
        printf("%d ", head->position);
        head = head->next;
    }
}
