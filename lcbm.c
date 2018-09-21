#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int position;
    struct node *next, *tail;
} Node;

void insert(Node** head, Node** tail, int newPosition);
void delete(Node** head, int newPosition);
void printList(Node* head);

int main(void){
    Node *head = NULL, *tail = NULL;

    int peopleIN;
    scanf("%d", &peopleIN);
    while (peopleIN--){
        int newPosition;
        scanf("%d", &newPosition);
        insert(&head, &tail, newPosition);
    }
    int peopleOUT;
    scanf("%d", &peopleOUT);
    while (peopleOUT--){
        int newPosition;
        scanf("%d", &newPosition);
        delete(&head, newPosition);
    }
    printList(head);
    printf("\n");
    return 0;
}

void insert(Node** head, Node** tail, int newPosition){
    Node *current = (Node *)malloc(sizeof(Node));
    current->position = newPosition;
    current->next = NULL;

    if(*head == NULL){
        *head = current;
        *tail = current;
        return;
    } else {
        (*tail)->next = current;
        *tail = (*tail)->next;
    }
}

void delete(Node **head, int position){ 
    Node* current = *head, *prev;

    if (current == NULL)
        return;
    if (current->position == position){
        *head = current->next;
        free(current);
        return; 
    }
    while (current->position != position){ 
        prev = current; 
        current = current->next; 
    }
    prev->next = current->next;  
    free(current); 
}

void printList(Node* head){
    while (head != NULL){
        printf("%d ", head->position);
        head = head->next;
    }
}
