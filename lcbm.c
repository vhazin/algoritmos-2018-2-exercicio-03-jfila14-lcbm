#include <stdio.h>
#include <stdlib.h>

struct Person{
    int position;
    struct Person *next;
};

void addPerson(struct Person **head_ref, int newPosition){
    struct Person *newPerson = (struct Person *)malloc(sizeof(struct Person));
    newPerson->position = newPosition;
    newPerson->next = (*head_ref);
    (*head_ref) = newPerson;
}

void removePerson(struct Person **head_ref, int newPosition){
    struct Person* auxiliar = *head_ref, *prev;

    if (auxiliar != NULL && auxiliar -> position == newPosition){
        *head_ref = auxiliar -> next; 
        free(auxiliar);
        return;
    }

    while (auxiliar != NULL && auxiliar->position != newPosition){
        prev = auxiliar;
        auxiliar = auxiliar->next;
    }

    if (auxiliar == NULL)
        return;

    prev -> next = auxiliar -> next;

    free(auxiliar);
}

void showQueue(struct Person *person){
    while (person != NULL){
        printf(" %d ", person -> position);
        person = person -> next;
    }
}

int main(){
    struct Person *head = NULL;

    int inputs = 0;
    scanf("%d", &inputs);

    while (inputs --){
        int address = 0;
        scanf("%d", address);
        addPerson(&head, address);
    };
    
    inputs = 0;
    while (inputs--){
        int address = 0;
        scanf("%d", address);
        removePerson(&head, address);
    };

    showQueue(head);

    return 0;
}
