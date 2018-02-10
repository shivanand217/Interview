#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert_back(struct node **head,int data) {
    if(*head == NULL) {
        (*head) = (struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = *head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next=(struct node *)malloc(sizeof(struct node));
    tmp=tmp->next;
    tmp->data=data;
    tmp->next=NULL;
}
void insert_front(struct node **head,int data) {
    if(*head == NULL) {
        (*head) = (struct node *)malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next=NULL;
        return;
    }
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=(*head);
    (*head)=tmp;
}
void display(struct node **head) {
    if(*head == NULL) {
        printf("list is empty\n");
        return;
    }
    struct node *tmp = *head;
    while( tmp != NULL ) {
        printf("%d ", tmp->data);
        tmp=tmp->next;
    }
    putchar('\n');
}
/** linked list is sorted **/
void remove_duplicate(struct node **head) {
    if(*head == NULL) {
        return;
    }
    struct node *tmp = *head;
    struct node *bekar = NULL;
    while( tmp->next != NULL ) {
        if(tmp->data == tmp->next->data) {
            bekar = tmp->next;
            tmp->next = tmp->next->next;
            free(bekar);
        } else {
            tmp = tmp->next;
        }
    }
}
int main() {
    struct node *head = NULL;

    insert_back(&head,11);
    insert_back(&head,11);
    insert_back(&head,11);
    insert_back(&head,12);
    insert_back(&head,23);
    insert_back(&head,44);
    insert_back(&head,44);
    insert_back(&head,50);
    insert_back(&head,59);

    insert_front(&head,11);
    display(&head);

    remove_duplicate(&head);
    display(&head);

    return 0;
}
